#include <cstdio>
#include <algorithm>

using namespace std;

class ele{
    public:
        int s, d;
        ele(){}
        ele(int _s, int _d){s = _s, d = _d;}
        bool operator<(const ele &A)const{
            return d < A.d;
        }
}e[100003];

int main(){

    int n, k, lim;
    scanf("%d %d %d", &n, &k, &lim);

    for(int i=0; i<n; i++){
        int c, d;
        scanf("%d %d", &c, &d);
        int s = 0;
        while(c--){
            int v;
            scanf("%d", &v);
            v--;
            s |= (1<<v);
        }
        e[i] = {s, d};
    }

    sort(e, e+n);

    int ans = 0;

    int chk[33] = {};
    int r = 0;
    for(int i=0; i<n; i++){
        while(r < n && e[r].d - e[i].d <= lim){
            int tot = 0, all = 0;
            for(int j=0; j<k; j++){
                if(e[r].s & (1<<j)){
                    chk[j]++;
                }
                if(chk[j]){
                    tot++;
                    if(chk[j] == r-i+1)all++;
                }
            }
            ans = max(ans, (tot-all) * (r-i+1));
            r++;
        }
        for(int j=0; j<k; j++){
            if(e[i].s & (1<<j)){
                chk[j]--;
            }
        }
    }

    printf("%d\n", ans);

}
