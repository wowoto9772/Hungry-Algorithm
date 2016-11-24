#include <cstdio>
#include <algorithm>

using namespace std;

int parent[1003];
int findParent(int v){
    if(parent[v] == v)return v;
    return parent[v] = findParent(parent[v]);
}

class ele{
    public:
        int a, b, c;
        bool operator<(const ele &A)const{
            return c < A.c;
        }
};

int main(){

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for(int i=1; i<=n; i++)parent[i] = i;

    for(int i=1; i<=k; i++){
        int a;
        scanf("%d", &a);
        parent[a] = n+1;
    }

    vector <ele> edge(m);

    for(int i=0; i<m; i++){
        scanf("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].c);
    }

    sort(edge.begin(), edge.end());

    int ans = 0;

    for (auto &e : edge){
        int a = e.a, b = e.b;
        if(findParent(a) == findParent(b))continue;
        parent[findParent(a)] = findParent(b);
        ans += e.c;
    }

    printf("%d\n", ans);

}
