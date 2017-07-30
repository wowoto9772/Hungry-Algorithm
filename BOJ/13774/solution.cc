#include <cstdio>
#include <string.h>

using namespace std;

bool palindrome(char *a){
    int s = strlen(a);
    for(int i=0; i<s/2; i++){
        if(a[i] != a[s-1-i])return false;
    }
    return true;
}

char str[33], out[33], ans[33];

int main(){
    
    while(scanf("%s", str) == 1){
        if(str[0] == '#')break;
        int s = strlen(str);
        for(int i=0; i<=30; i++)ans[i] = out[i] = 0;
        bool printed = false;
        for(int i=0; i<s; i++){
            int top = 0;
            for(int j=0; j<s; j++){
                if(i == j)continue;
                out[top++] = str[j];
            }
            out[top] = 0;
            if(palindrome(out)){
                printf("%s", out);
                printed = true;
                break;
            }
        }
        if(!printed)printf("not possible");
        puts("");
    }
    
}