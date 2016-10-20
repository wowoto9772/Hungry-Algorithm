#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

int e[23][23];
int n, m;

bool confirm(int tmp[][23], int a, int b){

    if(a){
        for(int i=1; i<=n; i++){
            swap(tmp[i][a], tmp[i][b]);
        }
    }

    for(int i=1; i<=n; i++){
        int no = 0;
        for(int j=1; j<=m; j++){
            if(tmp[i][j] != j)no++;
        }
        if(no == 0 || no == 2)continue;
        else{
            return false;
        }
    }

    return true;

}

int main(){

    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &e[i][j]);
        }
    }

    int t[23][23];
    memcpy(t, e, sizeof(t));

    if(confirm(t, 0, 0)){
        printf("YES\n");
        return 0;
    }

    for(int i=1; i<=m; i++){
        for(int j=i+1; j<=m; j++){
            memcpy(t, e, sizeof(t));
            if(confirm(t, i, j)){
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;

}
