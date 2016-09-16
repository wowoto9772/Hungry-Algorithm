#include <stdio.h>

int mid[100003];

int main(){

    int n;
    scanf("%d", &n);

    for(int fin=1; fin<=n; fin++){

        int v;
        scanf("%d", &v);

        mid[v] = v - fin;

    }

    for(int i=1; i<=n; i++)printf("%d\n", mid[i]);

}
