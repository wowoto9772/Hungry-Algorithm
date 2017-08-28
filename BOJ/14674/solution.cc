#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

class ele{
public:
    int i;
    ll x, y;
    ll a, b;
    ele(){}
    ele(int _i, ll _x, ll _y){
        i = _i, x = _x, y = _y;
        int g = gcd(x, y);
        a = x / g;
        b = y / g;
    }
    
    bool operator<(const ele &A)const{
        if(b*A.a == a*A.b){
            if(x == A.x)return i < A.i;
            return x < A.x;
        }
        return b*A.a > a*A.b;
    }
    
private:
    int gcd(int a, int b){
        int m = 1;
        while(m){
            m = a % b;
            a = b;
            b = m;
        }return a;
    }
    
}e[1003];

int main(){
    
    int n, k;
    scanf("%d %d", &n, &k);
    
    for(int i=0; i<n; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        e[i] = ele(a,b,c);
    }
    sort(e, e+n);
    
    for(int i=0; i<k; i++)printf("%d\n", e[i].i);

}