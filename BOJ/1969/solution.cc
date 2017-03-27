#include <cstdio>
#include <cstring>

using namespace std;

char str[1003][53];

int main(){
    
    int n, m;
    scanf("%d %d", &n, &m);

    int ans = 0;

    for(int i=0; i<n; i++)scanf("%s", str[i]);
    for(int k=0; k<m; k++){
        int c['Z'+3] = {};
        for(int i=0; i<n; i++){
            c[str[i][k]]++;
        }
        int v = 0, x;
        for(int i='A'; i<='Z'; i++){
            if(v < c[i])v = c[i], x = i;
        }
        printf("%c", x);
        ans += n-v;
    }

    printf("\n%d\n", ans);

}
