#include <stdio.h>

int dr[] = {1, 1, 0, -1, -1, 0};
int dc[] = {0, -1, -1, 0, 1, 1};
int x[1003][1003];

int v[10003];

int main(){
    
    int k = 1;
    int r = 500, c = 500;
    x[r][c] = 1;
    v[1] = 1;
    int top = 1, d = 0;
    int cnt[6] = {0,1};
    while(top < 10000){
        if(r+c == 1000 && r <= 500){
            c++;
            r--;
        }
        for(int i=1; i<=k; i++){
            r += dr[d];
            c += dc[d];
            int lo = 10000;
            bool used[6] = {};
            for(int j=0; j<6; j++)used[x[r+dr[j]][c+dc[j]]] = true;
            for(int j=1; j<=5; j++)if(!used[j] && lo > cnt[j])lo = cnt[j];
            for(int j=1; j<=5; j++)if(!used[j] && lo == cnt[j]){
                x[r][c] = v[++top] = j;
                cnt[j]++;
                break;
            }
        }
        d++;
        if(d >= 6){
            d -= 6;
            k++;
        }
    }
        
    int t;
    scanf("%d", &t);
    
    while(t--){
        int n;
        scanf("%d", &n);
        printf("%d\n", v[n]);
    }

}