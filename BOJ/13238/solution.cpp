#include <cstdio>
#include <set>

using namespace std;

int e[10003];

int main(){

    int n;
    scanf("%d", &n);

    multiset <int> my;

    for(int i=1; i<=n; i++){
        scanf("%d", &e[i]);
        my.insert(e[i]);
    }

    int ans = 0;

    for(int i=1; i<n; i++){
        multiset <int> ::iterator it = my.lower_bound(e[i]);
        my.erase(it);
        multiset <int> ::iterator lst = my.end();
        lst--;
        ans = max(ans, *lst - e[i]);
    }

    printf("%d\n", ans);

}
