#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class ele{
    public:
        int a, b, c, i;
        ele(){}
        ele(int _a, int _b, int _c, int _i){
            a = _a, b = _b, c = _c, i = _i;
        }
        bool operator<(const ele &A)const{
            if(a == A.a){
                if(b == A.b)return c < A.c;
                return b < A.b;
            }
            return a < A.a;
        }
};

int main(){

    int n;
    scanf("%d", &n);

    int ans = 0, x, y = 1;

    vector <ele> v;

    for(int i=0; i<n; i++){
        vector <int> a(3);
        for(int j=0; j<3; j++)scanf("%d", &a[j]);
        sort(a.begin(), a.end());
        if(ans < min({a[0], a[1], a[2]})){
            ans = min({a[0], a[1], a[2]});
            x = i+1;
        }
        v.emplace_back(a[2], a[1], a[0], i+1);
    }

    sort(v.begin(), v.end());

    int p, q;

    for(int i=v.size()-1; i>0; i--){
        if(v[i].a == v[i-1].a && v[i].b == v[i-1].b){
            if(ans < min(v[i].b, v[i].c+v[i-1].c)){
                ans = min(v[i].b, v[i].c+v[i-1].c);
                y = 2;
                p = min(v[i].i, v[i-1].i);
                q = max(v[i].i, v[i-1].i);
            }
        }
    }

    printf("%d\n", y);

    if(y == 1)printf("%d\n", x);
    else{
        printf("%d %d\n", p, q);
    }

}
