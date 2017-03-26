#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[270];

int main(){

    int t;
    scanf("%d", &t);

    fgets(str, sizeof(str), stdin); // for buffer

    while(t--){
        fgets(str, sizeof(str), stdin);
        int s = strlen(str);
        if(str[s-1] == '\n')s--;
        int c['z'+3] = {};
        for(int i=0; i<s; i++){
            c[str[i]]++;
        }
        int m = 0, v;
        for(int i='a'; i<='z'; i++){
            if(m < c[i]){
                m = c[i];
                v = i;
            }else if(m == c[i])v = '?';
        }

        printf("%c\n", v);
    }

}
