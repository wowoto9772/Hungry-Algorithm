#include <stdio.h>

int main(){

    int r, c;
    scanf("%d %d", &r, &c);

    c = r - c;

    printf("%.8lf\n", (double)c*c*100/(r*r));

}
