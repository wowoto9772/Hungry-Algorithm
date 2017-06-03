#include <cstdio>
#include <limits.h>
#include <cstring>
#include <queue>
#include <functional>

using namespace std;

char str[1003][103];
int d[1003], s;

int calc(int a, int b){
    int ret = 0;
    for(int i=0; i<s; i++){
        int v = abs(str[a][i] - str[b][i]);
        ret += v*v;
    }return ret;
}

int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)scanf("%s", str[i]);
    s = strlen(str[0]);

    int a, b;
    scanf("%d %d", &a, &b);
    a--, b--;

    for(int i=0; i<n; i++)d[i] = INT_MAX;

    priority_queue < pair <int,int> > q;
    q.emplace(0, a);
    d[a] = 0;

    while(!q.empty()){
        pair <int,int> f = q.top(); q.pop();
        if(d[f.second] < -f.first)continue;
        for(int i=0; i<n; i++){
            int cst = calc(f.second, i);
            if(-f.first + cst < d[i]){
                d[i] = -f.first + cst;
                q.emplace(-d[i], i);
            }
        }
    }
    printf("%d\n", d[b]);

}
