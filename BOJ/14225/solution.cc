#include <cstdio>

using namespace std;

int e[23];
bool chk[2000003];

int main(){
    
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)scanf("%d", &e[i]);
    
    for(int i=1; i<(1<<n); i++){
        int c = 0;
        for(int j=0; j<n; j++){
            if(i&(1<<j))c += e[j];
        }
        chk[c] = true;
    }
    
    for(int i=1;;i++){
        if(!chk[i]){
            printf("%d\n", i);
            return 0;
        }
    }

}