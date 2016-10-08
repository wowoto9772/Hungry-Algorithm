#include <cstdio>

using ll = long long;

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    int ans = 0;
    ll ans2 = 0;

    int p = 0, c = 0;
    ll m = 0;

    for(int i=1; i<=n; i++){
        int e;
        scanf("%d", &e);
        if(p <= e){
            p = e;
            m += e;
            c++;
        }else{
            if(ans < c){
                ans = c;
                ans2 = m;
            }
            p = m = e;
            c = 1;
        }
    }

    if(ans < c){
        ans = c;
        ans2 = m;
    }

    printf("%d %lld\n", ans, ans2);

}
