#include <cstdio>

using namespace std;

int p[1000003];

int findParent(int u){
    if(p[u] == u)return u;
    return p[u] = findParent(p[u]);
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<=n; i++)p[i] = i;

    while(m--){
        int x, a, b;
        scanf("%d %d %d", &x, &a, &b);

        if(x){
            if(findParent(a) == findParent(b))printf("YES\n");
            else
                printf("NO\n");
        }else{
            p[findParent(a)] = findParent(b);
        }
    }

}
