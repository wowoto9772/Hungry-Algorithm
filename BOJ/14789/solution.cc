#include <stdio.h>

int str_len(char *a){
    int r = 0;
    while(a[r] != 0)r++;
    return r;
}

char str[1003];

int main(){
    
    int t;
    scanf("%d", &t);
    
    int tc = 0;
    
    while(t--){
        
        int k;
        scanf("%s %d", str, &k);
        
        int s = str_len(str);
        int c = 0;
        
        for(int i=0; i+k-1<s; i++){
            if(str[i] == '-'){
                c++;
                for(int j=i; j<i+k; j++){
                    if(str[j] == '-')str[j] = '+';
                    else
                        str[j] = '-';
                }
            }
        }
        
        for(int i=s-k+1; i<s; i++){
            if(str[i] == '-')c = -1;
        }
        
        printf("Case #%d: ", ++tc);
        if(c == -1)printf("IMPOSSIBLE");
        else
            printf("%d", c);
        
        puts("");
        
    }

}