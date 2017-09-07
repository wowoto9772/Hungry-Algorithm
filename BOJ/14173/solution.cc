#include <cstdio>

using namespace std;

int main(){
    
    int mx = 10, Mx = 0, my = 10, My = 0;
    
    for(int i=0; i<2; i++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if(mx > a)mx = a;
        if(Mx < c)Mx = c;
        if(my > b)my = b;
        if(My < d)My = d;
    }
    
    int dx = Mx - mx, dy = My - my;
    if(dx < dy)dx = dy;
    
    printf("%d\n", dx*dx);

}