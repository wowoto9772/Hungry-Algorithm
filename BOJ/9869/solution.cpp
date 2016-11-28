#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    priority_queue <int> v;
    vector < vector <int> > e;
    e.resize(10003);

    for(int i=1; i<=n; i++){
        int g, d;
        scanf("%d %d", &g, &d);
        e[d].push_back(g);
    }

    int ans = 0;
    for(int i=10000; i>=1; i--){
        for(auto &_e : e[i]){
            v.push(_e);
        }
        if(v.empty())continue;
        ans += v.top();v.pop();
    }

    printf("%d\n", ans);

}
