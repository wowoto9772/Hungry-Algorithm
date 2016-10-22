#include <cstdio>

using namespace std;

int calc(int h, int m, int d){
    return h*3600+m*60+d;
}

int main(){

    int x, y, z;
    int a, b, c;
    scanf("%d:%d:%d", &x, &y, &z);
    scanf("%d:%d:%d", &a, &b, &c);

    int t = calc(a,b,c) - calc(x,y,z);
    if(t <= 0)t += 3600 * 24;

    printf("%02d:%02d:%02d\n", t/3600, (t%3600)/60, t%60);

}
