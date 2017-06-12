#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
using ll = long long;

int value(char *a){
    int s = strlen(a);
    int ret = 0, v = 1;
    for(int i=s-1; i>=0; i--){
        if(a[i] == '1')ret += v;
        v <<= 1;
    }
    return ret;
}

char str[33];
char out[63];

int main(){

    scanf("%s", str);
    ll p = (ll)value(str);
    scanf("%s", str);
    ll q = (ll)value(str);

    p *= q;

    int top = 0;
    while(p){
        if(p&1)out[top++] = '1';
        else
            out[top++] = '0';
        p >>= 1;
    }

    reverse(out, out+top);
    printf("%s\n", out);

}
