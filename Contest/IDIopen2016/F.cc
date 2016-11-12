#include <stdio.h>

#include <string.h>

#include <string>

#include <algorithm>

using namespace std;

using ll = long long;

const ll cmod = 1000000007;

string str;
char _str[10003];

char _wrd[23];
string wrd[1003];

ll c[1003], dp[10003];

int s, n;

ll dy(int x){

    if(x == s)return 1;

    ll &ret = dp[x];

    if(ret != -1)return ret;

    ret = 0;

    for(int i=0; i<n; i++){

        int w = wrd[i].size();

        if(x+w <= s){

            if(str.substr(x,w) == wrd[i]){
                ret += c[i] * dy(x+w);
                ret %= cmod;
            }

        }

    }

    return ret;

}

int main(){

    scanf("%d", &n);

    scanf("%s", _str);

    s = strlen(_str);

    str = string(_str);

    for(int i=0; i<s; i++)dp[i] = -1;

    for(int i=0; i<n; i++){

        scanf("%s %lld", _wrd, &c[i]);

        wrd[i] = string(_wrd);

    }

    printf("%lld\n", dy(0));

}
