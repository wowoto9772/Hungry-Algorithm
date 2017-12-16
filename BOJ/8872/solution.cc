#include <stdio.h>

template <class T> void swap(T &a, T &b){
    T t = a;
    a = b;
    b = t;
}

template <class T> T max(T a, T b){
    if(a < b)a = b;
    return a;
}

template <class T> T min(T a, T b){
    if(a > b)a = b;
    return a;
}

template <class T>
class Vector{
    public:
    
    T* arr;
    T* tarr;
    int _cap, _size;
    
    Vector(){ arr = new T[4]; _cap = 4; _size = 0; }
    Vector(int n){
        arr = new T[n];
        _cap = _size = n;
    }
    Vector(int n, T v){
        arr = new T[n];
        _cap = _size = n;
        for(int i=0; i<n; i++)arr[i] = v;
    }
    
    void resize(int n){
        arr = new T[n];
        _cap = _size = n;
    }
    
    void resize(int n, T v){
        arr = new T[n];
        _cap = _size = n;
        for(int i=0; i<n; i++)arr[i] = v;
    }
    
    int size(){return _size;}
    
    T back(){
        return arr[size-1];
    }
    
    void push_back(T x){
        if (_size == _cap){
            T* tmp = new T[_cap * 2];
            for (int i = 0; i < _size; i++)tmp[i] = arr[i];
            _cap *= 2;
            delete[] arr;
            arr = tmp;
        }
        arr[_size++] = x;
    }    

    bool empty(){
        return !(_size);
    }
    
    void clear(){ _cap = 4; _size = 0; delete[] arr; arr = new T[4]; }
    ~Vector(){ delete[] arr; }
    
    void StableSort(int l, int r){
        tarr = new T[_size];
        Divide(l, r);
    }

    private:
    void Merge(int l, int mid, int r){
        int ind = l;

        int pl = l, pr = mid + 1;
        while (pl <= mid && pr <= r){
            if (arr[pl] > arr[pr]){
                tarr[ind] = arr[pr];
                pr++, ind++;
            }
            else{
                tarr[ind] = arr[pl];
                pl++, ind++;
            }
        }

        if (pr == r + 1){
            for (int i = pl; i <= mid; i++)tarr[ind++] = arr[i];
        }
        else{ // pl = mid
            for (int i = pr; i <= r; i++)tarr[ind++] = arr[i];
        }

        // Conquer
        for (int i = l; i <= r; i++){
            arr[i] = tarr[i];
        }
    }

    void Divide(int l, int r){
        if (l < r){
            int m = (l + r) / 2;
            Divide(l, m);
            Divide(m + 1, r);
            Merge(l, m, r);
        }
    }
        
};

class ele{
    public:
    int a, c;
    ele(){}
    ele(int _a, int _c){
        a = _a, c = _c;
    }
};

Vector < ele > edge[100003];

int u, top, ans;
int d[100003], p[100003];
bool vst[100003];

void sortThree(int a[3]){
    if(a[0] > a[1])swap(a[0], a[1]);
    if(a[0] > a[2])swap(a[0], a[2]);
    if(a[1] > a[2])swap(a[1], a[2]);
}

class dat{
    public:
    int a, prev;
    dat(){}
    dat(int _a, int _prev){
        a = _a, prev = _prev;
    }
}q[100003];

void findDiameter(int c, int save_mode){
    
    d[c] = 0;
    p[c] = c;
    
    int front = 0, tale = 0;
    q[tale++] = dat(c, -1);
    
    while(front < tale){        
        dat cur = q[front++];
        vst[cur.a] = true;
        for(int i=0; i<edge[cur.a].size(); i++){
            ele son = edge[cur.a].arr[i];
            if(cur.prev == son.a)continue;
            if(save_mode)p[son.a] = cur.a;
            d[son.a] = d[cur.a] + son.c;
            if(d[u] < d[son.a])u = son.a;
            q[tale++] = dat(son.a, cur.a);
        }
    }
        
}

int n, l;
void calcAnswer(){
    int diameterCandidate = 0;
    int radiusCandidate[3] = {};
    int rtop = 0;
    for(int i=0; i<n; i++)vst[i] = false, p[i] = -1;
    for(int i=0; i<n; i++){
        if(vst[i])continue;
        
        u = i;
        findDiameter(i, 0); // do not save prev node
        int s = u; // tree's diameter's terminal (1)
        findDiameter(s, 1); // do save prev node
        int e = u; // tree's diameter's terminal (2)
        
        if(diameterCandidate < d[u])diameterCandidate = d[u];
        
        int radius = d[u];
        e = p[e];
        while(e != s){
            radius = min(radius, max(d[e], d[u] - d[e])); // tree's radius is always on tree's diameter nodes.
            e = p[e];
        }
        
        if(rtop < 3)radiusCandidate[rtop++] = radius;
        else{
            sortThree(radiusCandidate);
            if(radiusCandidate[0] < radius)radiusCandidate[0] = radius;
        }
    }
    
    ans = diameterCandidate;
    
    if(rtop == 2){
        ans = max(ans, radiusCandidate[0] + radiusCandidate[1] + l);
    }else if(rtop == 3){
        sortThree(radiusCandidate);
        ans = max(ans, radiusCandidate[1] + radiusCandidate[2] + l);
        ans = max(ans, radiusCandidate[0] + radiusCandidate[1] + 2*l);
    }
    
}

int main(){
    
    int m;
    scanf("%d %d %d", &n, &m, &l);
        
    for(int i=0; i<n; i++)edge[i].clear();
    
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back(ele(b, c));
        edge[b].push_back(ele(a, c));
    }
    
    for(int i=0; i<n; i++)p[i] = -1;
    
    top = 0;    
    calcAnswer();
    printf("%d\n", ans);

}
