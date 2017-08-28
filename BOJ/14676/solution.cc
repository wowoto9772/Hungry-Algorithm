#include <cstdio>
#include <vector>

using namespace std;

int c[100003];

int main(){
    
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    vector < vector <int> > pre;
    pre.resize(n+1);
    
    while(m--){
        int x, y;
        scanf("%d %d", &x, &y);
        
        pre[y].push_back(x);
    }
    
    bool flag = true;
    
    while(k-- && flag){
        int t, a;
        scanf("%d %d", &t, &a);
        
        if(t == 1){
            for(auto &e : pre[a]){
                if(c[e] == 0){
                    flag = false;
                }
            }
            if(flag)c[a]++;
        }else{
            if(c[a] == 0)flag = false;
            c[a]--;
        }
    }
    
    if(!flag)printf("Lier!");
    else{
        printf("King-God-Emperor");
    }

}