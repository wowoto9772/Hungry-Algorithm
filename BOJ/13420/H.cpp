#include <cstdio>

using ll = long long;
using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        ll a, b, d;
        char c;

        scanf("%lld %c %lld = %lld", &a, &c, &b, &d);

        if(c == '+')a += b;
        else if(c == '-')a -= b;
        else if(c == '*')a *= b;
        else
            a /= b;

        if(a == d)printf("correct\n");
        else
            printf("wrong answer\n");

    }

}
