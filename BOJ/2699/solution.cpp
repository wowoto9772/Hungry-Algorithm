#include <cstdio>
#include <limits.h>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

struct point {
    ll x, y;
    point(ll x = 0, ll y = 0) :x(x), y(y) {}
    bool operator<(const point &A)const {
        if (x == A.x)return y < A.y;
        return x < A.x;
    }
    bool operator==(const point &A)const{
        return x == A.x && y == A.y;
    }
};

int ccw(point &a, point &b, point &c) {
    ll dx1, dx2, dy1, dy2;
    dx1 = b.x - a.x;
    dy1 = b.y - a.y;
    dx2 = c.x - b.x;
    dy2 = c.y - b.y;

    ll ret = dx1*dy2 - dx2*dy1;
    if (ret < 0)return -1;
    else if (ret > 0)return 1;
    else
        return 0;
}

class ConvexHull {
    public:
        int n;
        vector <point> v, u, d;
        vector <point> c;
        ConvexHull(int _n) : n(_n), v(_n), u(_n), d(_n), c(_n*2) {}

        /* return convex hull's size. and v-1 is the number of convex hull's points */
        int solve() {
            int iu, id;
            id = iu = -1;
            sort(v.begin(), v.end());
            int cnt;

            for (int i = 0; i < n; i++) {
                while (iu > 0 && ccw(u[iu - 1], u[iu], v[i]) >= 0) iu--;
                u[++iu] = v[i];
                while (id > 0 && ccw(d[id - 1], d[id], v[i]) <= 0) id--;
                d[++id] = v[i];
            }
            for (cnt = 0; cnt <= iu; cnt++) {
                c[cnt] = u[cnt];
            }
            for (int i = id - 1; i >= 0; i--) {
                c[cnt++] = d[i];
            }
            return cnt;
        }
};

int main() {

    int t;
    scanf("%d", &t);

    while(t--){ 

        int n;
        scanf("%d", &n);

        ConvexHull h(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld", &h.v[i].x, &h.v[i].y);
        }

        int s = h.solve()-1;
        printf("%d\n", s);

        int p = 0;

        for(int i=1; i<s; i++){
            if(h.c[i].y > h.c[p].y){
                p = i;
            }else if(h.c[i].y == h.c[p].y){
                if(h.c[i].x < h.c[p].x){
                    p = i;
                }
            }
        }

        for(int i=p; i<s; i++)printf("%lld %lld\n", h.c[i].x, h.c[i].y);
        for(int i=0; i<p; i++)printf("%lld %lld\n", h.c[i].x, h.c[i].y);

    }
}
