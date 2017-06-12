#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class dat{
public:
    int a, b, c;
    dat(){}
    dat(int _a, int _b, int _c){
        a = _a, b = _b, c = _c;
    }
    bool operator<(const dat &A)const{
        return c < A.c;
    }
};

char sexy[1003];
int par[1003];

int findParent(int a){
    if(par[a] == a)return a;
    return par[a] = findParent(par[a]);
}

int main(){
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++)scanf(" %c", &sexy[i]);
    
    vector < dat > edge;
    
    for(int i=1; i<=m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(sexy[a] != sexy[b])edge.emplace_back(a, b, c);
    }
    
    for(int i=1; i<=n; i++)par[i] = i;
    
    sort(edge.begin(), edge.end());
    
    int ans = 0;
    int c = 0;
    
    for(auto &e : edge){
        if(findParent(e.a) == findParent(e.b))continue;
        c++;
        ans += e.c;
        par[findParent(e.a)] = findParent(e.b);
    }
    
    if(c != n-1)ans = -1;
    
    printf("%d\n", ans);

}