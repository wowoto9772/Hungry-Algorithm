#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;

// from https://github.com/kcm1700/algorithms
// in: n, m, graph
// out: match, matched
// vertex cover: (reached[0][left_node] == 0) || (reached[1][right_node] == 1)
struct BipartiteMatching
{
    int n, m;
    vector<vector<int> > graph;
    vector<int> matched, match;
    vector<int> edgeview;
    vector<int> level;
    vector<int> reached[2];
    BipartiteMatching(int n, int m) : n(n), m(m), graph(n), matched(m, -1), match(n, -1) {}

    bool assignLevel()
    {
        bool reachable = false;
        level.assign(n, -1);
        reached[0].assign(n, 0);
        reached[1].assign(m, 0);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (match[i] == -1) {
                level[i] = 0;
                reached[0][i] = 1;
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (auto adj : graph[cur]) {
                reached[1][adj] = 1;
                auto next = matched[adj];
                if (next == -1) {
                    reachable = true;
                }
                else if (level[next] == -1) {
                    level[next] = level[cur] + 1;
                    reached[0][next] = 1;
                    q.push(next);
                }
            }
        }
        return reachable;
    }

    int findpath(int nod) {
        for (int &i = edgeview[nod]; i < graph[nod].size(); i++) {
            int adj = graph[nod][i];
            int next = matched[adj];
            if (next >= 0 && level[next] != level[nod] + 1) continue;
            if (next == -1 || findpath(next)) {
                match[nod] = adj;
                matched[adj] = nod;
                return 1;
            }
        }
        return 0;
    }

    int solve()
    {
        int ans = 0;
        while (assignLevel()) {
            edgeview.assign(n, 0);
            for (int i = 0; i < n; i++)
                if (match[i] == -1)
                    ans += findpath(i);
        }
        return ans;
    }
};

vector < vector < int > > v;

int main(){
    
    int m;
    scanf("%*d %d", &m);
    v.resize(m);
    
    map <int,int> mp;
    int top = 0;
    
    for(int i=0; i<m; i++){
        int x;
        scanf("%d", &x);
        for(int j=2; j*j <= x; j++){
            if(x%j)continue;
            if(mp.find(j) == mp.end())mp[j] = top++;
            v[i].push_back(j);
            while(!(x%j))x /= j;
        }
        if(x != 1){
            if(mp.find(x) == mp.end())mp[x] = top++;
            v[i].push_back(x);
        }
    }
            
    BipartiteMatching btm(m,mp.size());
    for(int i=0; i<m; i++){
        for(int j=0; j<v[i].size(); j++){
            btm.graph[i].push_back(mp[v[i][j]]);
        }
    }
    
    printf("%d\n", btm.solve());

}