#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    vector <int> l;
    l.push_back(0);

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        int d, v;
        scanf("%d %d", &d, &v);
        while(d--)l.push_back(v);
    }

    int c = 0;
    int ans = 0;

    for(int i=1; i<=m; i++){
        int d, v;
        scanf("%d %d", &d, &v);
        for(int j=c+1; j<=c+d; j++)ans = max(ans, v-l[j]);
        c += d;
    }

    printf("%d\n", ans);

}
