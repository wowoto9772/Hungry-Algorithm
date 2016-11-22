#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    priority_queue < int > q;

    vector < vector <int> > v;
    v.resize(1001);
    
    for(int i=1; i<=n; i++){
        int t, p;
        scanf("%d %d", &t, &p);
        v[t].push_back(p);
    }

    int ans = 0;

    for(int i=1000; i>=1; i--){
        for(auto &e : v[i]){
            q.emplace(e);
        }
        if(!q.empty()){
            ans += q.top(); q.pop();
        }
    }

    printf("%d\n", ans);

}
