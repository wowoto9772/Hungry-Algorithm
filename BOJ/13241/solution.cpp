#include <cstdio>

using ll = long long;

using namespace std;

ll gcd(ll a, ll b){
    ll c = 1;
    while(c){
        c = a % b;
        a = b;
        b = c;
    }return a;
}

ll lcm(ll a, ll b){
    return a / gcd(a,b) * b;
}

int main(){

    ll a, b;
    scanf("%lld %lld", &a, &b);

    printf("%lld\n", lcm(a,b));

}
