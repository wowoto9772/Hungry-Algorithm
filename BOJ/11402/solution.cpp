#include <stdio.h>

#include <vector>

using namespace std;

using ll = long long;

ll nCm[2003][2003];

void make_data(int mod){
    nCm[0][0] = 1;
    for(int i=1; i<=mod; i++){
        nCm[i][0] = 1;
        for(int j=1; j<=i; j++){
            nCm[i][j] = nCm[i-1][j-1] + nCm[i-1][j];
            nCm[i][j] %= mod;
        }
    }
}

int main(){

    ll n, k;
    int m;
    scanf("%lld %lld %d", &n, &k, &m);

    make_data(m);

    // lucas's thorem

    vector <int> p, q;

    while(n){
        p.push_back(n%m);
        q.push_back(k%m);

        n /= m, k /= m;
    }

    ll ans = 1;

    for(int i=0; i<p.size(); i++){
        ans *= nCm[p[i]][q[i]];
        ans %= m;
    }

    printf("%lld\n", ans);

}
