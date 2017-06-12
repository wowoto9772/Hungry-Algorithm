#include <cstdio>
#include <cstring>

using namespace std;

int d[] = {8, 10, 16};
char str[10];

int main(){
    
    int t;
    scanf("%d", &t);
    
    while(t--){
        int k;
        scanf("%d %s", &k, str);
        int s = strlen(str);
        
        printf("%d ", k);
        for(int i=0; i<3; i++){
            int x = 1;
            int e = 0;
            bool imp = false;
            for(int j=s-1; j>=0; j--){
                int v = str[j] - '0';
                if(v >= d[i]){
                    imp = true;
                    break;
                }
                e += v * x;
                x *= d[i];
            }
            if(imp)printf("0 ");
            else
                printf("%d ", e);
        }printf("\n");
    }

}