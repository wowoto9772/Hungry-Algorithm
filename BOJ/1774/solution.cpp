#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Edge{
    public:
    int a, b;
    double c;
    Edge(){}
    Edge(int _a, int _b, double _c){
        a = _a, b = _b, c = _c;
    }
    bool operator<(const Edge &A)const{
        return c < A.c;
    }
};

int p[1003], x[1003], y[1003];

int findParent(int u){
    if(p[u] == u)return u;
    return p[u] = findParent(p[u]);
}

double cst(int i, int j){
    long long a = x[i] - x[j], b = y[i] - y[j];
    return sqrt(a*a+b*b);
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        scanf("%d %d", &x[i], &y[i]);
        p[i] = i;
    }

    for(int i=1; i<=m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        p[findParent(a)] = findParent(b);
    }

    vector <Edge> edge;

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            edge.emplace_back(i, j, cst(i, j));
        }
    }

    sort(edge.begin(), edge.end());

    double ans = 0;

    for(auto &e : edge){
        int a = e.a, b = e.b;
        double c = e.c;
        if(findParent(a) == findParent(b))continue;
        p[findParent(a)] = findParent(b);
        ans += c;
    }

    printf("%.2lf\n", ans);

}
