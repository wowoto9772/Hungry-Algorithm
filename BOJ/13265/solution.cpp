#include <cstdio>

#include <vector>

#include <queue>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n, m;
        scanf("%d %d", &n, &m);

        vector <int> c(n+1, -1);

        vector < vector <int> > lnk;
        lnk.resize(n+1);

        for(int i=1; i<=m; i++){
            int a, b;
            scanf("%d %d", &a, &b);

            lnk[a].push_back(b);
            lnk[b].push_back(a);
        }

        bool flag = true;

        for(int i=1; i<=n && flag; i++){

            if(c[i] == -1){

                queue <int> q;
                
                q.push(i);
                
                c[i] = 0;

                while(!q.empty() && flag){

                    int f = q.front(); q.pop();

                    for(int j=0; j<lnk[f].size(); j++){

                        int g = lnk[f][j];

                        if(c[g] == -1){
                            c[g] = 1 ^ c[f];
                            q.push(g);
                        }else{
                            if(c[g] != (1^c[f])){
                                flag = false;
                            }
                        }

                    }

                }

            }

        }

        if(flag)printf("possible\n");
        else{
            printf("impossible\n");
        }

    }

}
