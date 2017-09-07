#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

vector < vector <int> > lnk;

int x[203], y[203], p[203];

int main(){
    
    int n;
    scanf("%d", &n);
    
    lnk.resize(n);
    
    for(int i=0; i<n; i++){
        scanf("%d %d %d", &x[i], &y[i], &p[i]);
        p[i] *= p[i];   
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j){
                int d = (x[j]-x[i]) * (x[j]-x[i]) + (y[j]-y[i]) * (y[j]-y[i]);
                if(d <= p[i])lnk[i].push_back(j);
            }
        }
    }
    
    int ans = 0;
    for(int i=0; i<n; i++){
        bool chk[203] = {};
        chk[i] = true;
        int c = 0;
        queue <int> q;
        q.push(i);
        
        while(!q.empty()){
            int f = q.front(); q.pop();
            for(auto &e : lnk[f]){
                if(chk[e])continue;
                chk[e] = true;
                c++;
                q.push(e);
            }
        }
        
        if(ans < c)ans = c;
    }
    
    printf("%d\n", ++ans);

}