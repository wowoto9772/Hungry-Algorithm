#include <stdio.h>

char str[1000003];

int main(){

    int n;
    scanf("%d", &n);

    n <<= 1;
    n++;

    int s;
    scanf("%d", &s);

    scanf("%s", str);

    int ans = 0;

    for(int i=0; i<s; i++){
        if(str[i] == 'I'){
            char *d = "IO";
            int f = 0;
            for(int j=i; j<s; j++){
                if(d[f] != str[j] || j == s-1){
                    int l = j - i + 1;
                    if(d[f] != str[j])l--;
                    if(n <= l){
                        ans += ((l-n)>>1)+1;
                    }
                    i = j - 1;
                    if(d[f] == str[j])i++;
                    break;
                }
                f ^= 1;
            }
        }
    }

    printf("%d\n", ans);

}
