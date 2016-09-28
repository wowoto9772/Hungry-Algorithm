#include <cstdio>

#include <vector>

#include <queue>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    vector < vector <int> > cont;

    cont.resize(n+1);

    for(int i=1; i<=n; i++){

        int c;
        scanf("%d", &c);

        for(int j=1; j<=c; j++){

            int a;
            scanf("%d", &a);

            cont[i].push_back(a);
            cont[a].push_back(i);

        }
        
    }

    vector < int > c(n+1, -1);

    for(int i=1; i<=n; i++){

        if(c[i] != -1)continue;

        queue <int> q;

        q.push(i);
        c[i] = 0;

        while(!q.empty()){

            int f = q.front(); q.pop();

            for(int j=0; j<cont[f].size(); j++){

                int g = cont[f][j];

                if(c[g] == -1){
                    c[g] = !c[f];
                    q.push(g);
                }

            }

        }

    }

    int k = 0;
    for(int i=1; i<=n; i++)if(c[i] == 0)k++;

    printf("%d\n", k);

    for(int i=1; i<=n; i++)if(c[i] == 0)printf("%d ", i);

    printf("\n");

    printf("%d\n", n-k);

    for(int i=1; i<=n; i++)if(c[i])printf("%d ", i);

}
