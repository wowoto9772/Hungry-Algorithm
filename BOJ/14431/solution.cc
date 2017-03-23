#include <cstdio>
#include <cmath>

#include <limits.h>

#include <vector>
#include <queue>

#include <functional>

using namespace std;

bool isPrime(int v){
    if(v == 2)return true;
    else if(v < 2 || (v&1) == 0)return false;
    else{
        for(int i=3; i*i <= v; i+=2){
            if(v%i)continue;
            return false;
        }return true;
    }
}

int d[4003];
pair <int,int> p[4003];
int dist(int i, int j){
    int a = (p[i].first - p[j].first);
    int b = (p[i].second - p[j].second);
    int c = a*a+b*b;
    c = (int)sqrt((double)c);
    return c;
}

int main(){
        
    for(int i=4001; i<=4002; i++)scanf("%d %d", &p[i].first, &p[i].second);

    int n;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%d %d", &p[i].first, &p[i].second);
    }
    
    p[0] = p[4001];
    p[n+1] = p[4002];
    n++;
    
    vector < vector < pair<int,int> > > lnk;
    lnk.resize(n+1);
    
    for(int i=0; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            int cst = dist(i,j);
            if(isPrime(cst)){
                lnk[i].emplace_back(j, cst);
                lnk[j].emplace_back(i, cst);
            }
        }
    }
    
    priority_queue < pair<int,int>, vector < pair<int,int> >, greater < pair<int,int> > > q;
    q.emplace(0, 0);
    
    for(int i=1; i<=n; i++)d[i] = INT_MAX;
    
    while(!q.empty()){
        pair <int,int> f = q.top(); q.pop();
        if(d[f.first] < f.second)continue;
        for(auto &e : lnk[f.first]){
            pair <int,int> g = {e.first, e.second+f.second};
            if(d[g.first] > g.second){
                d[g.first] = g.second;
                q.emplace(g);
            }
        }
    }
    
    if(d[n] == INT_MAX)d[n] = -1;
    printf("%d\n", d[n]);

}