#include <cstdio>
#include <algorithm>

using namespace std;

int e[1003];

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        scanf("%d", &n);

        for(int i=0; i<n; i++){
            scanf("%d", &e[i]);
        }

        sort(e, e+n);
        int ans = 0;

        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                int g = 2 * e[j] - e[i];
                int l = j+1, r = n-1, m;
                while(l <= r){
                    m = (l+r) / 2;
                    if(e[m] == g)break;
                    else if(e[m] > g)r = m - 1;
                    else
                        l = m + 1;
                }

                if(e[m] == g)ans++;
            }
        }

        printf("%d\n", ans);

    }

}
