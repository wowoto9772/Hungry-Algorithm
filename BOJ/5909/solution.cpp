#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

map <int, map<int, map<int, map<int, int> > > > dp;

int n, tot;
int e[23];

int dy(int i, int a, int b, int c){
    if(a < b)swap(a, b);
    if(a < c)swap(a, c);
    if(b < c)swap(b, c);
    if(i == n+1)return a;
    if(dp[i][a][b].find(c) != dp[i][a][b].end())return dp[i][a][b][c];
    int &ret = dp[i][a][b][c];
    ret = min({dy(i+1, a+e[i], b, c), dy(i+1, a, b+e[i], c), dy(i+1, a, b, c+e[i])});
    return ret;
}

int main(){

    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &e[i]);
        tot += e[i];
    }

    printf("%d\n", dy(1, 0, 0, 0));

}
