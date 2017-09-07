#include <cstdio>
#include <cstring>

using namespace std;

char a[13], b[13];

int main(){
    
    int n;
    scanf("%d", &n);
    
    int c['z'+3] = {};

    while(n--){
        
        scanf("%s %s", a, b);
        
        int x = strlen(a), y = strlen(b);
        int p['z'+3] = {}, q['z'+3] = {};
        for(int i=0; i<x; i++)p[a[i]]++;
        for(int i=0; i<y; i++)q[b[i]]++;
        
        for(int i='a'; i<='z'; i++){
            if(p[i] > q[i])c[i] += p[i];
            else
                c[i] += q[i];
        }
    
    }
    
    for(int i='a'; i<='z'; i++)printf("%d\n", c[i]);

}