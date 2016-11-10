#include <cstdio>
#include <map>

using ll = long long;
using namespace std;

int s[50003];

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int d, n;
        scanf("%d %d", &d, &n);

        map <int, int> cnt;
        cnt[0] = 1;
        
        ll ans = 0;

        for(int i=1; i<=n; i++){
            scanf("%d", &s[i]);
            s[i] += s[i-1];
            s[i] %= d;
            ans += cnt[s[i]];
            cnt[s[i]]++;
        }

        printf("%lld\n", ans);

    }

}
