#include <cstdio>

using namespace std;

char str[13][13];

int main(){
    
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    
    for(int i=0; i<m; i++)scanf("%s", str[i]);
    for(int i=0; i<m*k; i++){
        for(int j=0; j<n*k; j++){
            char c = str[i/k][j/k];
            printf("%c", c);
        }puts("");
    }

}