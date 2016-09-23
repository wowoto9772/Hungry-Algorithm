#include <cstdio>

using namespace std;

int e[93];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)scanf("%d", &e[i]);

    if(n == 1){
        if(e[1] == 0)printf("UP\n");
        else if(e[1] == 15)printf("DOWN\n");
        else
            printf("-1\n");
    }
    else{
        if(e[n-1] < e[n]){
            if(e[n] == 15)printf("DOWN\n");
            else
                printf("UP\n");
        }
        else if(e[n-1] > e[n]){
            if(e[n] == 0)printf("UP\n");
            else
                printf("DOWN\n");
        }
        else
            printf("-1\n");
    }

    return 0;

}
