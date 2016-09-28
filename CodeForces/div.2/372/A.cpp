#include <stdio.h>

int t[100003];

int main(){

    int n, c;
    scanf("%d %d", &n, &c);

    int a = 0;

    bool flag = false;

    for(int i=1; i<=n; i++){
        scanf("%d", &t[i]);
        if(t[i-1]+c < t[i])a = 1;
        else{
            a++;
        }
    }

    printf("%d\n", a);

    return 0;

}
