#include <cstdio>
#include <cstring>

using namespace std;

char str[1003][1003];
char in[1003];

int mp['z'+3];

int main(){

    mp['a'] = mp['b'] = mp['c'] = '2';
    mp['d'] = mp['e'] = mp['f'] = '3';
    mp['g'] = mp['h'] = mp['i'] = '4';
    mp['j'] = mp['k'] = mp['l'] = '5';
    mp['m'] = mp['n'] = mp['o'] = '6';
    mp['p'] = mp['q'] = mp['r'] = mp['s'] = '7';
    mp['t'] = mp['u'] = mp['v'] = '8';
    mp['w'] = mp['x'] = mp['y'] = mp['z'] = '9';

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)scanf("%s", str[i]);
    scanf("%s", in);

    int s = strlen(in);
    int ans = 0;

    for(int i=1; i<=n; i++){
        int k = strlen(str[i]);
        if(s == k){
            bool flag = false;
            for(int j=0; j<s && !flag; j++){
                if(in[j] != mp[str[i][j]])flag = true;
            }
            ans += !flag;
        }
    }

    printf("%d\n", ans);

}
