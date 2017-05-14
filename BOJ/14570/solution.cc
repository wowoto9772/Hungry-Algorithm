#include <cstdio>

using namespace std;
using ll = long long;

class ele{
public:
    int l, r;
}tree[200003];

ll cnt[200003][2];

void dfs(ll n, int c, int p){
    if(n == 0)return ;
    if(tree[c].l == -1 && tree[c].r == -1)cnt[c][p] = n;
    else if(tree[c].l == -1)dfs(n, tree[c].r, p);
    else if(tree[c].r == -1)dfs(n, tree[c].l, p);
    else{
        dfs(n/2+(n&1), tree[c].l, p);
        dfs(n/2, tree[c].r, p);
    }
}

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d %d", &tree[i].l, &tree[i].r);
    }

    ll k;
    scanf("%lld", &k);

    dfs(k, 1, 0);
    dfs(k-1, 1, 1);

    for(int i=1; i<=n; i++)if(cnt[i][0] != cnt[i][1])printf("%d\n", i);

}
