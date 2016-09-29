#include <cstdio>
#include <memory.h>
#include <limits.h>

#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

struct MaxFlowDinic
{
    typedef long long flow_t;

    struct Edge
    {
        int next;
        int inv; /* inverse edge index */
        flow_t res; /* residual */
    };

    int n;
    vector<vector<Edge>> graph;

    vector<unsigned> q, l, start;

    void Init(int _n){
        n = _n;
        graph.resize(n);
        for(int i = 0; i < n; i++) graph[i].clear();
    }
    void AddNodes(int count) {
        n += count;
        graph.resize(n);
    }
    void AddEdge(int s, int e, flow_t cap, flow_t caprev = 0) {
        Edge forward = { e, graph[e].size(), cap };
        Edge reverse = { s, graph[s].size(), caprev };
        graph[s].push_back(forward);
        graph[e].push_back(reverse);
    }

    bool AssignLevel(int source, int sink) {
        int t = 0;
        memset(&l[0], 0, sizeof(l[0]) * l.size());
        l[source] = 1;
        q[t++] = source;
        for(int h = 0; h < t && !l[sink]; h++) {
            int cur = q[h];
            for(unsigned i = 0; i < graph[cur].size(); i++) {
                int next = graph[cur][i].next;
                if (l[next]) continue;
                if (graph[cur][i].res > 0) {
                    l[next] = l[cur] + 1;
                    q[t++] = next;
                }
            }
        }
        return l[sink] != 0;
    }

    flow_t BlockFlow(int cur, int sink, flow_t currentFlow) {
        if (cur == sink) return currentFlow;
        for(unsigned &i = start[cur]; i < graph[cur].size(); i++) {
            int next = graph[cur][i].next;
            if (graph[cur][i].res == 0 || l[next] != l[cur]+1)
                continue;
            if (flow_t res = BlockFlow(next, sink, min(graph[cur][i].res, currentFlow))) {
                int inv = graph[cur][i].inv;
                graph[cur][i].res -= res;
                graph[next][inv].res += res;
                return res;
            }
        }
        return 0;
    }

    flow_t Solve(int source, int sink)
    {
        q.resize(n);
        l.resize(n);
        start.resize(n);
        flow_t ans = 0;
        while(AssignLevel(source,sink)) {
            memset(&start[0], 0, sizeof(start[0])*n);
            while(flow_t flow = BlockFlow(source,sink,numeric_limits<flow_t>::max())) {
                ans += flow;
            }
        }
        return ans;
    }
};

char str[15][15];

vector < int > door;
vector < int > people;

int d[150][150];
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
int v[15][15];

int main(){

    int r, c;
    scanf("%d %d", &r, &c);

    for(int i=1; i<=r; i++){
        scanf("%s", str[i]+1);
        for(int j=1; j<=c; j++){
            v[i][j] = (i-1)*c+j;
        }
    }

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(str[i][j] == '.'){
                people.push_back(v[i][j]);
            }else if(str[i][j] == 'D'){

                int s = v[i][j];
                door.push_back(s);

                for(int k=1; k<=r*c; k++)d[s][k] = INT_MAX;

                queue < pair<int,int> > q;
                q.emplace(i, j);

                d[s][s] = 0;

                while(!q.empty()){

                    pair<int,int> f = q.front(); q.pop();

                    int p = v[f.first][f.second];

                    for(int k=0; k<4; k++){
                        pair<int,int> g = {f.first + dr[k], f.second + dc[k]};
                        
                        if(g.first < 1 || g.first > r || g.second < 1 || g.second > c)continue;
                        if(str[g.first][g.second] != '.')continue;

                        int a = v[g.first][g.second];
 
                        if(d[s][a] == INT_MAX){
                            d[s][a] = d[s][p] + 1;
                           q.emplace(g);
                        }

                    }

                }

            }
        }
    }

    int le = 1, ri = 2*r*c, m;

    int ans = INT_MAX;

    while(le <= ri){

        m = (le + ri) >> 1;
        MaxFlowDinic mf;
        mf.Init(m+door.size()+people.size()+2);

        int src = 0, snk = m+door.size()+people.size()+1;

        for(int i=1; i<=m; i++){
            // time
            mf.AddEdge(src, i, INT_MAX);
            for(int j=0; j<door.size(); j++){ 
                // time and door
                mf.AddEdge(i, m+j+1, 1);
            }
        }

        for (int i=0; i<door.size(); i++){
            int s = door[i];
            for(int j=0; j<people.size(); j++){
                int a = people[j];
                if(d[s][a] <= m){
                    // door and people
                    mf.AddEdge(m+i+1, m+door.size()+j+1, 1);
                }
            }
        }

        for(int i=0; i<people.size(); i++){ 
            // people
            mf.AddEdge(m+door.size()+i+1, snk, 1);
        }

        if(mf.Solve(src, snk) == people.size()){
            ri = m - 1;
            ans = min(ans, m);
        }else{
            le = m + 1;
        }

    }

    if(ans == INT_MAX){
        printf("impossible\n");
        return 0;
    }

    printf("%d\n", ans);

}
