#include <stdio.h>

int gcd(int a, int b){
   
    int m = 1;

    while(m){
        m = a % b;
        a = b;
        b = m;
    }

    return a;
    
}

bool chk[100003][103];
int g[103][103];

int e[100003];

int main(){

    for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++){
            g[i][j] = gcd(i, j);
        }
    }

    int n;

    while(scanf("%d", &n) == 1 && n){

        for(int i=1; i<=n; i++){
            scanf("%d", &e[i]);
            for(int j=1; j<=100; j++){
                chk[i][j] = false;
            }

        }

        bool ans[103] = {0};

        for(int i=1; i<=n; i++){

            if(chk[i][e[i]])continue;

            chk[i][e[i]] = true;
            ans[e[i]] = true;

            int j = i, c = e[i];

            while(j < n){
                
                int nc = g[c][e[j+1]];

                if(chk[j+1][nc])break;

                chk[j+1][nc] = true;
                ans[nc] = true;

                j++;
                c = nc;

            }
        
        }
        
        int c = 0;
        for(int i=1; i<=100; i++)if(ans[i])c++;

        printf("%d\n", c);

    }

}
