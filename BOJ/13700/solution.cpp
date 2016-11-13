#include <cstdio>
#include <queue>

using namespace std;

int c[100003];
bool cant[100003];

int main(){

    int n, s, d, f, b, k;
    scanf("%d %d %d %d %d %d", &n, &s, &d, &f, &b, &k);

    for(int i=1; i<=n; i++)c[i] = -1;

    for(int i=1; i<=k; i++){
        int v;
        scanf("%d", &v);
        cant[v] = true;
    }

    queue <int> q;
    q.push(s);
    c[s] = 0;

    while(c[d] == -1 && !q.empty()){
        int x = q.front(); q.pop();
        if(x+f <= n && c[x+f] == -1 && !cant[x+f]){
            c[x+f] = c[x]+1;
            q.push(x+f);
        }
        if(x-b > 0 && c[x-b] == -1 && !cant[x-b]){
            c[x-b] = c[x]+1;
            q.push(x-b);
        }
    }

    if(c[d] == -1)printf("BUG FOUND\n");
    else
        printf("%d\n", c[d]);

}
