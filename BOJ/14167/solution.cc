#include <cstdio>
#include <queue>

using namespace std;

int x[1003], y[1003];

int main(){
    
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)scanf("%d %d", &x[i], &y[i]);
    
    int l = 0, r = 1300000000, m;
    int ans = 0;
    
    while(l <= r){
        
        m = (l+r) >> 1;
        
        queue <int> q;
        vector <bool> chk(n);
        chk[0] = true;
        q.push(0);
        
        int c = 0;
        
        while(!q.empty()){
            int f = q.front(); q.pop();
            for(int j=0; j<n; j++){
                if(chk[j])continue;
                int d = (x[f]-x[j])*(x[f]-x[j]) + (y[f]-y[j])*(y[f]-y[j]);
                if(d <= m){
                    chk[j] = true;
                    q.push(j);
                }
            }
            c++;
        }
        
        if(c == n){
            r = m - 1;
            ans = m;
        }
        else{
            l = m + 1;
        }
        
    }
    
    printf("%d\n", ans);

}