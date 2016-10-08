#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int depth[23];

int main(){

    int n;
    scanf("%d", &n);

    int root = 0;

    vector < vector <int> > lnk;
    lnk.resize(n+1);

    queue <int> q;

    for(int i=1; i<=n; i++){
        depth[i] = -1;
        int e;
        scanf("%d", &e);
        if(e <= 0){
            q.push(i);
            depth[i] = 0;
        }
        else
            lnk[e].push_back(i);
    }

    while(!q.empty()){
        int f = q.front(); q.pop();
        for(int j=0; j<lnk[f].size(); j++){
            int g = lnk[f][j];
            depth[g] = depth[f]+1;
            q.push(g);
        }
    }

    for(int i=1; i<=n; i++)printf("%d\n", depth[i]);

}
