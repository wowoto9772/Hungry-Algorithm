#include <cstdio>
#include <time.h>
#include <stdlib.h>

using namespace std;
using ll = long long;

struct point{
    ll x, y;
    point(ll x = 0, ll y = 0) :x(x), y(y){}
    bool operator<(const point &A)const{
        if (x == A.x)return y < A.y;
        return x < A.x;
    }
}e[100003];

int ccw(const point &a, const point &b, const point &c) {
    ll dx1, dx2, dy1, dy2;
    dx1 = b.x - a.x;
    dy1 = b.y - a.y;
    dx2 = c.x - b.x;
    dy2 = c.y - b.y;
    ll ret = dx1*dy2 - dx2*dy1;
    if (ret < 0)return -1;
    else if (ret > 0)return 1;
    else return 0;
}

int main(){
    
    int n, p;
    scanf("%d %d", &n, &p);
    
    int goal = (n * p) / 100;
    if((n*p)%100)goal++;
    
    for(int i=0; i<n; i++){
        scanf("%lld %lld", &e[i].x, &e[i].y);
    }
    
    if(n == 1){
        printf("possible\n");
        return 0;
    }
    
    srand(time(0));
    
    for(int x=1; x<=777; x++){
        int a = rand() % n;
        int b = a;
        while(a == b){
            b = rand() % n;
        }
        int c = 0;
        for(int i=0; i<n; i++){
            c += (ccw(e[a],e[b],e[i]) == 0);
        }
        if(c >= goal){
            printf("possible\n");
            return 0;
        }
    }
    printf("impossible\n");

}