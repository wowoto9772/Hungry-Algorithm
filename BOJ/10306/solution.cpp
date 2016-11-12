#include <cstdio>
#include <cstring>
#include <vector>

using ll = long long;
using namespace std;

char str[13];

int val(char c){
    if(c >= 'A')return 10 + c-'A';
    else
        return c - '0';
}

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        scanf("%s", str);
        int s = strlen(str);

        ll ans = 0, t = 1;

        for(int i=s-1; i>=0; i--){
            ans += (ll)t * val(str[i]);
            t <<= 5;
        }

        printf("%lld\n", ans);

        vector <int> out;
        while(ans){
            int v = ans % 32;
            for(int i=1; i<=5; i++){
                out.push_back(v&1);
                v >>= 1;
            }
            ans >>= 5;
        }

        for(int i=out.size()-1; i>=0; i--)printf("%d", out[i]);
        printf("\n");

    }

}
