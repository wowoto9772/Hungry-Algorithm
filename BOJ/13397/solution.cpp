#include <cstdio>
#include <algorithm>

using namespace std;

int e[10003];

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    for(int i=1; i<=n; i++)scanf("%d", &e[i]);

    int l = 0, r = 10000, m;

    int ans = 10000;

    while(l <= r){

        m = (l+r) >> 1;

        int c = 1;
        int le = e[1], ri = e[1];

        for(int i=2; i<=n; i++){

            int nle = le, nri = ri;

            nle = min(nle, e[i]);
            nri = max(nri, e[i]);

            if(nri - nle > m){
                le = ri = e[i];
                c++;
            }else{
                le = nle, ri = nri;
            }

        }

        if(c <= k){
            ans = min(ans, m);
            r = m - 1;
        }else{
            l = m + 1;
        }

    }

    printf("%d\n", ans);

}
