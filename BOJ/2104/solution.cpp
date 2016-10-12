#include <cstdio>
#include <stack>
#include <algorithm>

using ll = long long;

using namespace std;

ll s[100003];

int main(){
    
    int n;
    scanf("%d", &n);

    stack < pair<int,int> > up;

    ll ans = 0;

    for(int i=1; i<=n; i++){
        int e;
        scanf("%d", &e);

        s[i] = s[i-1] + e;

        if(up.empty() || up.top().second <= e)up.emplace(i, e);
        else{
            int l = i;
            while(!up.empty() && up.top().second >= e){
                l = up.top().first;
                ans = max(ans, (ll)e * (s[i] - s[up.top().first-1]));
                ans = max(ans, (ll)up.top().second * (s[i-1] - s[up.top().first-1]));
                up.pop();
            }
            up.emplace(l, e);
        }
    }

    while(!up.empty()){
        ans = max(ans, (ll)up.top().second * (s[n] - s[up.top().first-1]));
        up.pop();
    }

    printf("%lld\n", ans);

}

