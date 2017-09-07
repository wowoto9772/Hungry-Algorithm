#include <cstdio>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

int a[100003], b[100003];

int main(){
    
    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);
    
    for(int i=1; i<=n; i++)scanf("%d", &a[i]);
    
    priority_queue < pair<int,int> > q;
    
    for(int i=1; i<=n; i++){
        int x;
        scanf("%d", &x);
        q.emplace(-x, i);
    }
    
    pair <int,int> p = q.top(); q.pop();
    int cand = l - a[p.second];
    b[p.second] = l;
    
    while(!q.empty()){
        p = q.top(); q.pop();
        cand++;
        int x = (cand + a[p.second]);
        b[p.second] = x;
    }
    
    minv = (1<<31)-1;
    for(int i=1; i<=n; i++){
        if(minv > b[i])minv = b[i];
    }
    int up = l - minv;
    if(up < 0)up = 0;
    for(int i=1; i<=n; i++){
        b[i] += up;
        if(b[i] < l || b[i] > r){
            printf("-1");
            return 0;   
        }
    }
            
    for(int i=1; i<=n; i++){
        printf("%d ", b[i]);
    }

}