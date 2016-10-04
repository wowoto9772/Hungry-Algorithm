#include <cstdio>

using namespace std;

char o[27];

int t[103], c[103];

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    for(int i=1; i<=k; i++){
        scanf(" %d %c", &t[i], &c[i]);
        t[i] %= n;
    }

    for(int i=0; i<n; i++)o[i] = '?';

    o[0] = c[k];

    bool used['Z'+3] = {};

    used[o[0]] = true;

    int p = 0;

    bool inv = false;

    for(int i=k; i>=2 && !inv; i--){
        
        p += t[i];
        p %= n;

        if(used[c[i-1]]){
            if(o[p] == c[i-1])continue;
            else{
                inv = true;
            }
        }

        if(o[p] == '?'){
            o[p] = c[i-1];
            used[o[p]] = true;
        }else{
            inv = true;
        }

    }

    if(inv)printf("!\n");
    else{
        printf("%s\n", o);
    }

}
