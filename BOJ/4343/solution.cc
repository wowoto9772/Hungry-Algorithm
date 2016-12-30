#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int p[503];

int findParent(int a){
    if(p[a] == a)return a;
    return p[a] = findParent(p[a]);
}

double d[503][503];
int x[503], y[503];

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int k, n;
        scanf("%d %d", &k, &n);
        for(int i=1; i<=n; i++)scanf("%d %d", &x[i], &y[i]);
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                d[i][j] = sqrt((double)(x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            }
        }
        double l = 0, r = 1000000000, m;
        while( r-l >= 1e-9 ){
            m = (l+r) / 2;
            vector < pair <int,int> > edge;
            for(int i=1; i<=n; i++){
                for(int j=i+1; j<=n; j++){
                    if(d[i][j] <= m){
                        edge.emplace_back(i, j);
                    }
                }
                p[i] = i;
            }
            for(auto &e : edge){
                int a = e.first, b = e.second;
                if(findParent(a) == findParent(b))continue;
                p[findParent(a)] = findParent(b);
            }
            int c = 0;
            for(int i=1; i<=n; i++)if(p[i] == i)c++;
            if(c <= k){
                r = m;
            }else{
                l = m;
            }
        }
        printf("%.2lf\n", m);
    }

}
