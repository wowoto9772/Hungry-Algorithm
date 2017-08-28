#include <cstdio>
#include <cstring>

using namespace std;

const int NO = 255555;

char str[53][53];

int main(){
    
    int n;
    scanf("%d", &n);
        
    for(int i=0; i<n; i++){
        scanf("%s", str[i]);
    }
    
    int s = strlen(str[0]);

    char target[53] = {};
    strcpy(target, str[0]);
    
    int ans = NO;
    for(int i=0; i<s; i++){

        int r = 0;
        
        for(int j=0; j<n; j++){
            char my[53] = {};
            strcpy(my, str[j]);
            int c = 0;
            while(strcmp(my, target) != 0){
                c++;
                if(c >= s+1)break;
                r++;
                char l = my[0];
                for(int k=0; k<s-1; k++)my[k] = my[k+1];
                my[s-1] = l;
            }
            if(c >= s+1){
                r = NO;
                break;
            }
        }
        
        if(ans > r)ans = r;
        
        char l = target[0];
        for(int j=0; j<s-1; j++)target[j] = target[j+1];
        target[s-1] = l;
    }
    
    if(ans == NO)ans = -1;
    
    printf("%d\n", ans);

}