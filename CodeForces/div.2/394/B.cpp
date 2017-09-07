#include <cstdio>

using namespace std;

bool x[53];
int s[53];

int main(){
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        int k;
        scanf("%d", &k);
        x[k] = true;
    }
    
    for(int i=0; i<n; i++){
        scanf("%d", &s[i]);
    }
    
    for(int i=0; i<m; i++){
        bool p = true;
        for(int j=0; j<n && p; j++){
            p &= x[(i+s[j]) % m];
        }
        if(p){
            printf("YES");
            return 0;
        }
    }
    
    printf("NO");
    
}

