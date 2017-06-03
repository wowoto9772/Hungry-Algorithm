#include <cstdio>

using namespace std;

int main(){

    int h, m;
    scanf("%d %d", &h, &m);

    int x, y;
    scanf("%d %d", &x, &y);

    int d;
    scanf("%d", &d);
    
    int ans = 0;

    while(h*60+m <= x*60+y){
        if(h/10 == d || h%10 == d || m/10 == d || m%10 == d)ans++;
        m++;
        if(m == 60)h++, m=0;
    }

    printf("%d\n", ans);

}
