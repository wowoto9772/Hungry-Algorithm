#include <stdio.h>

int main(){

    int a, b;
    scanf("%d %d", &a, &b);

    int L = 0, R = 0;

    while(a != 1 || b != 1){

        if(a > b){
            int c = a / b;
            if(!(a % b))c--;
            L += c;
            a -= c * b;
        }else{
            int c = b / a;
            if(!(b % a))c--;
            R += c;
            b -= c * a;
        }

    }

    printf("%d %d\n", L, R);

}
