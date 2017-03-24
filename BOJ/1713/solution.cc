#include <cstdio>

using namespace std;

int c[103], l[103];

int main(){
    
    int n;
    scanf("%d", &n);
    
    int k;
    scanf("%d", &k);
    
    int r = 0;
    
    for(int i=1; i<=k; i++){
        int e;
        scanf("%d", &e);
        
        if(l[e])c[e]++;
        else{
        
            if(r < n){
                l[e] = i, r++;
                c[e]++;
            }else{
                int mini = 1003;
                for(int j=1; j<=100; j++)if(l[j] && mini > c[j])mini = c[j];
            
                int x;
            
                int lst = 1003;
                for(int j=1; j<=100; j++){
                	if(mini != c[j])continue;
                    if(lst > l[j])lst = l[j], x = j;
                    else if(lst == c[j] && l[j] < lst){
                        lst = l[j], x = j;
                    }
                }
            
                c[x] = 0;
                l[x] = 0;
                l[e] = i;
                c[e]++;
            }
        }
    }
    
    for(int i=1; i<=100; i++)if(l[i])printf("%d ", i);

}