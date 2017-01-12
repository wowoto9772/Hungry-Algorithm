#include <cstdio>

using namespace std;

int main(){

    int n, l, d;
    scanf("%d %d %d", &n, &l, &d);
    
    // 0 ~ l
    // l+5 ~ 2*l+5
    
    int c = 0;
    int ends = (l+5)*(n-1) + l;
    
    for(int t=d;;t+=d){
        if(t%(l+5) < l){
            if(t >= ends){
                printf("%d\n", t);
                break;
            }
            continue;
        }else{
            printf("%d\n", t);
            break;
        }
    }

}
