#include <cstdio>
#include <algorithm>

using ll = long long;
using namespace std;

int mp[2000003], e[3003];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &e[i]);
        mp[e[i]] = i; 
    }

    ll ans = 0;

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            int st = e[j];
            int gap = e[j] - e[i];
            int c = 2;
            while(mp[st+gap]){
                st += gap;
                c++;
            }

            if(c >= 3){
                ans = max(ans, (ll)e[i]*c + (ll)gap*((c-1)*c/2));
            }
        }
    }

    printf("%d\n", ans);

}
