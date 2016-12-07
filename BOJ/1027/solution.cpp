#include <cstdio>
#include <algorithm>

using ll = long long;
using namespace std;

struct point{
    ll x, y;
    point(ll x = 0, ll y = 0) :x(x), y(y){}
    bool operator<(const point &A)const{
        if (x == A.x)return y < A.y;
        return x < A.x;
    }
};

struct edge{
    point A, B;
    edge(){}
    edge(point _A, point _B) : A(_A), B(_B){}
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

bool specialmeets(const edge &L, const edge &R){
    int Llx = min(L.A.x, L.B.x), Lrx = max(L.A.x, L.B.x);
    int Lly = min(L.A.y, L.B.y), Lry = max(L.A.y, L.B.y);
    int Rlx = min(R.A.x, R.B.x), Rrx = max(R.A.x, R.B.x);
    int Rly = min(R.A.y, R.B.y), Rry = max(R.A.y, R.B.y);
    if(max(Llx, Rlx) <= min(Lrx, Rrx)){
        if(max(Lly, Rly) <= min(Lry, Rry)){
            return true;
        }
    }
    return false;
}

bool meets(const edge &L, const edge &R){
    if(ccw(L.A, L.B, R.A) == 0 && 0 == ccw(L.A, L.B, R.B)){
        // on same line
        return specialmeets(L, R);
    }
    if(ccw(L.A, L.B, R.A) * ccw(L.A, L.B, R.B) <= 0){
        if(ccw(R.A, R.B, L.A) * ccw(R.A, R.B, L.B) <= 0){
            return true;
        }
    }
    return false;
}

int h[53];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &h[i]);
    }

    int ans = 0;

    for(int i=1; i<=n; i++){
        int tmp = 0;
        for(int j=i-1; j>=1; j--){
            edge A = {point(i, h[i]), point(j, h[j])};
            bool flag = false;
            for(int k=j+1; k<i && !flag; k++){
                edge B = {point(k, 0), point(k, h[k])};
                flag |= meets(A, B);
            }
            tmp += !flag;
        }
        for(int j=i+1; j<=n; j++){
            edge A = {point(i, h[i]), point(j, h[j])};
            bool flag = false;
            for(int k=i+1; k<j && !flag; k++){
                edge B = {point(k, 0), point(k, h[k])};
                flag |= meets(A, B);
            }
            tmp += !flag;
        }
        ans = max(ans, tmp);
    }

    printf("%d\n", ans);

}
