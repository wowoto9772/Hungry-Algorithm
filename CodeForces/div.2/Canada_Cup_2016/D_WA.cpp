#include <cstdio>

#include <algorithm>

using ll = long long;

using namespace std;

class ele{
    public:
        ll b, w;
        ele(){}
        ele(ll _b, ll _w){
            b = _b, w = _w;
        }

        bool operator<(const ele &A)const{
            if(w-b == A.w-A.b)return b > A.b;
            return (w-b) < (A.w-A.b);
        }
}e[300003];

int main(){

    int n;
    scanf("%d", &n);

    int c = 0;

    ll B;
    scanf("%lld %*lld", &B);

    for(int i=0; i<n-1; i++){

        ll b, w;
        scanf("%lld %lld", &b, &w);
        e[i] = {b, w};

        if(B < b)c++;
    }

    int ans = ++c;

    sort(e, e+n-1);

    ll l = 0, r = B, m;

    while(l <= r){
        m = (l+r) / 2;
        c = 0;
        ll t = 0;
        for(int i=0; i<n-1; i++){
            if(e[i].b > B-m){
                ll dt = e[i].w - e[i].b + 1;
                if(t + dt > m)c++;
                else{
                    t += dt;
                }
            }
        }
//        printf("%lld %lld %lld\n", m, t, c);
        ans = min(ans, ++c);
        if(t <= m)l = m + 1;
        else
            r = m - 1;
    }

    printf("%d\n", ans);

}
