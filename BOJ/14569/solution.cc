#include <cstdio>
#include <vector>

using namespace std;
using ll = long long;

ll e[1003];

int main(){

    int n;
    scanf("%d", &n);

    vector < vector <int> > v;
    for(int i=0; i<n; i++){
        int c;
        scanf("%d", &c);
        while(c--){
            int v;
            scanf("%d", &v);
            v--;
            e[i] |= (1LL<<v);
        }
    }

    int m;
    scanf("%d", &m);

    while(m--){
        ll cmp = 0;
        int c;
        scanf("%d", &c);
        int ans = 0;
        for(int i=1; i<=c; i++){
            int v;
            scanf("%d", &v);
            v--;
            cmp |= (1LL<<v);
        }
        for(int i=0; i<n; i++)if((e[i] & cmp) == e[i])ans++;
        printf("%d\n", ans);
    }

}
