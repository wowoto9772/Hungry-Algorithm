#include <cstdio>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        long double a;
        scanf("%Lf", &a);

        // (a-2*b) * (a-2*b) * b
        // f(b) = 4b^3 - 4ab^2 + a^2b
        // f'(b) = 12b^2 - 8ab + a^2 = (6b-a)(2b-a)

        printf("%.10Lf\n", a/6.0);

    }

}
