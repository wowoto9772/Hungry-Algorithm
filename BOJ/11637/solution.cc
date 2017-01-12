#include <cstdio>

using namespace std;

int e[13];

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        scanf("%d", &n);

        int v = 0, k = 0, l, m = 0;
        for(int i=1; i<=n; i++){
            scanf("%d", &e[i]);
            v += e[i];
            if(k < e[i]){
                k = e[i];
                l = i;
                m = 1;
            }else if(k == e[i])m++;
        }

        if(m > 1)printf("no winner");
        else{
            if(e[l] > v/2)printf("majority");
            else{
                printf("minority");
            }
            printf(" winner %d", l);
        }

        printf("\n");

    }

}
