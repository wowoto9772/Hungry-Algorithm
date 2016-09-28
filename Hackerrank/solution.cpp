#include <stdio.h>

#include <vector>

using namespace std;

using ll = long long;

vector < vector <int> > lnk;

vector < int > d, c;
vector < ll > s, s2;

ll graph(int depth, int root){

    d[root] = depth;

    if(!lnk[root].empty()){

        for(int i=0; i<lnk[root].size(); i++){

            int son = lnk[root][i];

            ll add = graph(depth+1, son);

            c[root] += (c[son] + 1);

        }

    }

}

int main(){

    int n;
    scanf("%d", &n);

    lnk.resize(n+1);
    d.resize(n+1);
    s.resize(n+1);
    s2.resize(n+1);
    c.resize(n+1);

    for(int i=2; i<=n; i++){

        int p;
        scanf("%d", &p);

        lnk[p].push_back(i);

    }

    graph(0, 1);

}
