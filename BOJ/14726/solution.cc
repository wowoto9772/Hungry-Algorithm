#include <cstdio>
#include <cstring>

using namespace std;

char str[19];

int main(){

    int t;
    scanf("%d", &t);
    
    while(t--){
        scanf("%s", str);
        int s = strlen(str);
        
        bool even = true;
        int flg = 0;
        for(int i=s-1; i>=0; i--){
            even ^= true;
            int v = str[i] - '0';
            if(even){
                v <<= 1;
                flg += (v/10) + (v%10);
            }else{
                flg += v;
            }
        }
    
        if(flg%10)printf("F\n");
        else
            printf("T\n");
    }

}