#include <cstdio>
#include <vector>

using ll = long long;

const ll lmod = 1000000007;

using namespace std;

vector <int> P;
bool p[1003];

void calc(vector <int> &Q, int v, bool add){
    for(int i=0; i<P.size() && P[i] <= v; i++){
        int j = P[i];
        while(j <= v){
            Q[i] = Q[i] + v / j * ((add) ? 1 : -1);
            j *= P[i];
        }
    }
}

int main(){

    for(int i=2; i*i <= 1000; i++){
        if(!p[i]){
            for(int j=i*i; j<=1000; j+=i)p[j] = true;
        }
    }

    for(int i=2; i<=1000; i++)if(!p[i])P.push_back(i);

    int t;
    scanf("%d", &t);

    while(t--){

        int n, k;
        scanf("%d %d", &n, &k);

        vector <int> q(P.size());

        calc(q, n, true);
        calc(q, k, false);
        calc(q, n-k, false);

        ll ans = 1;

        for(int i=0; i<q.size(); i++){
            for(int j=1; j<=q[i]; j++){
                ans *= P[i];
                ans %= lmod;
            }
        }

        printf("%lld\n", ans);

    }

}
