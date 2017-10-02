#include <cstdio>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

struct point{
    int x, y;
    bool operator<(const point &A)const{
        if(x == A.x)return y < A.y;
        return x < A.x;
    }
};

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

struct ConvexHull {
    vector <point> pts;
    /* return convex hull's size. and v-1 is the number of convex hull's points */
    vector <point> convex() {
        int n = pts.size();
        vector <point> u, d;

        sort(pts.begin(), pts.end()); // sort x and y
        for (int i = 0; i < n; i++) {
            while (u.size() >= 2 && ccw(u[u.size()-2], u.back(), pts[i]) < 0)
                u.pop_back();

            u.push_back(pts[i]);

            while (d.size() >= 2 && ccw(d[d.size()-2], d.back(), pts[i]) > 0)
                d.pop_back();

            d.push_back(pts[i]);
        }
        u.insert(u.end(), next(d.rbegin()), prev(d.rend()));
        return u;
    }
};

ll dist(const point &a, const point &b){
    ll l = (a.x - b.x), r = (a.y - b.y);
    return l*l + r*r;
}

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        scanf("%d", &n);

        vector <point> v(n);
        for(int i=0; i<n; i++)scanf("%d %d", &v[i].x, &v[i].y);
        ConvexHull cv;
        cv.pts = v;
        vector <point> ans = cv.convex();

        int l = 0, r = 0;
        int x = 0, y = 0;
        ll tmp = 0;

        while(l < ans.size()){
            ll d = dist(ans[l], ans[r]);
            if(tmp < d){
                tmp = d;
                x = l, y = r;
            }
            ll nd = dist(ans[l], ans[(r+1) % ans.size()]);
            if(d <= nd){
                r++;
                r %= ans.size();
            }else{
                l++;
            }
        }

        printf("%d %d %d %d\n", ans[x].x, ans[x].y, ans[y].x, ans[y].y);
    }

}
