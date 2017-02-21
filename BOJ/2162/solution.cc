#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct point{
    int x, y;
    point(int _x = 0, int _y = 0){
        x = _x, y = _y;
    }
    bool operator<(const point &A)const{
        if (x == A.x)return y < A.y;
        return x < A.x;
    }
};

struct edge{
    point A, B;
    edge(){}
    edge(point _A, point _B){
        A = _A, B = _B;
    }
};

int ccw(point &a, point &b, point &c) {
    int dx1, dx2, dy1, dy2;
    dx1 = b.x - a.x;
    dy1 = b.y - a.y;
    dx2 = c.x - b.x;
    dy2 = c.y - b.y;
    int ret = dx1*dy2 - dx2*dy1;
    if (ret < 0)return -1;
    else if (ret > 0)return 1;
    else return 0;
}

bool specialmeets(edge &L, edge &R){
    int Llx = min(L.A.x, L.B.x), Lrx = max(L.A.x, L.B.x);
    int Lly = min(L.A.y, L.B.y), Lry = max(L.A.y, L.B.y);
    int Rlx = min(R.A.x, R.B.x), Rrx = max(R.A.x, R.B.x);
    int Rly = min(R.A.y, R.B.y), Rry = max(R.A.y, R.B.y);
    if(max(Llx, Rlx) <= min(Lrx, Rrx)){
        if(max(Lly, Rly) <= min(Lry, Rry)){
            return true;
        }
    }
    return false;
}

bool meets(edge &L, edge &R){
    if(ccw(L.A, L.B, R.A) == 0 && 0 == ccw(L.A, L.B, R.B)){
        // on same line
        return specialmeets(L, R);
    }
    if(ccw(L.A, L.B, R.A) * ccw(L.A, L.B, R.B) <= 0){
        if(ccw(R.A, R.B, L.A) * ccw(R.A, R.B, L.B) <= 0){
            return true;
        }
    }
    return false;
}

int chk[3003];
edge ed[3003];

int main(){

    int n;
    scanf("%d", &n);

    vector < vector <int> > lnk;
    lnk.resize(n);

    for(int i=0; i<n; i++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        ed[i] = edge(point(a,b), point(c,d));
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(meets(ed[i], ed[j]))lnk[i].push_back(j), lnk[j].push_back(i);
        }
        chk[i] = -1;
    }

    int ans = 0;
    int cnt = 0;

    for(int i=0; i<n; i++){
        if(chk[i] == -1){
            cnt++;
            queue <int> q;
            q.push(i);
            chk[i] = i;
            int c = 1;
            while(!q.empty()){
                int f = q.front();q.pop();
                for(auto &e : lnk[f]){
                    if(chk[e] == -1){
                        q.push(e);
                        chk[e] = i;
                        c++;
                    }
                }
            }
            if(ans < c)ans = c;
        }
    }

    printf("%d\n%d\n", cnt, ans);

}
