#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool fo[100003], ba[100003];

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    vector < vector <int> > lnk[2];
    for(int i=0; i<2; i++)lnk[i].resize(n+1);
    
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        lnk[0][a].push_back(b);
        lnk[1][b].push_back(a);
    }

    queue <int> q;
    q.push(1);
    fo[1] = true;
    while(!q.empty()){
        int f = q.front();q.pop();
        for(auto &e : lnk[0][f]){
            if(fo[e])continue;
            fo[e] = true;
            q.push(e);
        }
    }

    q.push(n);
    ba[n] = true;
    while(!q.empty()){
        int f = q.front();q.pop();
        for(auto &e : lnk[1][f]){
            if(ba[e])continue;
            ba[e] = true;
            q.push(e);
        }
    }

    int c;
    scanf("%d", &c);

    while(c--){
        int v;
        scanf("%d", &v);

        if(fo[v] && ba[v])printf("Defend the CTP");
        else
            printf("Destroyed the CTP");
        printf("\n");
    }

}
