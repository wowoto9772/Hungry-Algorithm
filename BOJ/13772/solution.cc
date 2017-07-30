#include <cstdio>
#include <string.h>

char str[3333];

int main(){
    
    int t;
    scanf("%d", &t);
    
    fgets(str, sizeof(str), stdin);
    
    while(t--){
        fgets(str, sizeof(str), stdin);
        int s = strlen(str);
        int c = 0;
        for(int i=0; i<s; i++){
            if(str[i] == 'A' || str[i] == 'D' || str[i] == 'O' || str[i] == 'P' || str[i] == 'Q' || str[i] == 'R')c++;
            else if(str[i] == 'B')c += 2;
        }
        printf("%d\n", c);
    }

}