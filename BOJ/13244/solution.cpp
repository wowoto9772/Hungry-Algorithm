#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int p[1003];

int findParent(int parent){
    if(p[parent] == parent)return parent;
    return p[parent] = findParent(p[parent]);
}

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n, m;
        scanf("%d %d", &n, &m);

        for(int i=1; i<=n; i++)p[i] = i;

        bool cyc = false;

        vector < vector <int> > lnk;

        lnk.resize(n+1);

        for(int i=1; i<=m; i++){

            int a, b;
            scanf("%d %d", &a, &b);

            if(findParent(a) == findParent(b))cyc = true;
            else{
                p[findParent(a)] = findParent(b);
                lnk[a].push_back(b);
                lnk[b].push_back(a);
            }

        }

        if(cyc){
            printf("graph\n");
        }else{
            vector <bool> chk(n+1);
            queue <int> q;
            chk[1] = true;
            q.push(1);
            int c = 1;
            while(c < n && !q.empty()){
                int f = q.front(); q.pop();
                for(int i=0; i<lnk[f].size(); i++){
                    int g = lnk[f][i];
                    if(chk[g])continue;
                    chk[g] = true;
                    c++;
                    q.push(g);
                }
            }
            if(c == n)printf("tree\n");
            else
                printf("graph\n");
        }

    }

}
