#include <cstdio>

using namespace std;

using ll = long long;

int main(){

    ll x, y;
    scanf("%lld %lld", &x, &y);

    ll a, b;
    scanf("%lld %lld", &a, &b);

    // counter clock wise

    // k(a,b) + n(-b,a) = (x,y)
    // ak - bn = x
    // bk + an = y

    // abk - b^2n = bx
    // abk + a^2n = ay
    
    double n = (a*y - b*x) / (double)(b*b + a*a);
    double k = (x + b*n) / (double)a;

    printf("%.8lf\n%.8lf\n", k, n);

}

// if clock wise

// k(a,b) + n(b,-a) = (x,y)
