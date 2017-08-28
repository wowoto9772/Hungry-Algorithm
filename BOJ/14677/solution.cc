#include <cstdio>

using namespace std;

char str[1503];
char *bld = "BLD";

int main(){
    
    int n;
    scanf("%d", &n);
    
    scanf("%s", str);
    
    int r = 0;
    
    for(int i=0; i<3*n; i++){
        if(str[i] != 'B')continue;
        int p = 0;
        int q = 0;
        for(int j=i; j<3*n; j++){
            if(str[j] == bld[p]){
                p++, q++;
                if(p == 3)p = 0;
            }else{
                break;
            }
        }
        if(r < q)r = q;
    }
    
    printf("%d\n", r);

}