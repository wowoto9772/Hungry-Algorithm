#include <cstdio>

using namespace std;

int r[10003], p[10003];

int main(){
    
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);
    
    bool chk['Z'+3] = {};
    
    for(int i=1; i<=k; i++){
        scanf("%d %c", &r[i], &p[i]);
        if(i >= q)chk[p[i]] = true;
    }
    
    for(int i=1; i<=k; i++)if(r[i] == r[q])chk[p[i]] = true;
        
    if(r[q] > 0){
        chk['A'] = true;
        for(int i='A'; i<'A'+n; i++)if(!chk[i]){
            printf("%c ", i);
        }
    }else{
        printf("-1");
    }
}