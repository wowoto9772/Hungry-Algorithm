#include <cstdio>
#include <string>
#include <map>

using namespace std;
using ll = long long;

char a[13], b[4];

int main(){
    
    int n;
    scanf("%d", &n);
    
    map <string, int> cnt;
    
    while(n--){
        scanf("%s %s", a, b);
        string x = "";
        x += a[0];
        x += a[1];
        
        if(x == string(b))continue;
        
        x += string(b);
        cnt[x]++;
    }
    
    ll ans = 0;
    
    for(auto &e : cnt){
        string x = e.first;
        x = x.substr(2) + x.substr(0, 2);
        ans += (ll) (cnt[x] * e.second);
    }
    
    printf("%lld\n", ans>>1);

}