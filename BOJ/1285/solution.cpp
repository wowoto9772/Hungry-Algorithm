#include <stdio.h>

#include <memory.h>

#include <algorithm>

using namespace std;

char str[23][23];
char tmp[23][23];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s", str[i]);
    }

    int ans = n*n;

    for(int i=0; i<(1<<n); i++){
        memcpy(tmp, str, sizeof(str));
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                for(int k=0; k<n; k++){
                    if(tmp[j][k] == 'H')tmp[j][k] = 'T';
                    else
                        tmp[j][k] = 'H';
                }
            }
        }
        int f = 0;
        for(int j=0; j<n; j++){
            int e = 0;
            for(int k=0; k<n; k++){
                if(tmp[k][j] == 'T')e++;
            }
            f += min(e, n-e);
        }

        ans = min(ans, f);

    }

    printf("%d\n", ans);

}
