#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class ele{
    public:
        int i;
        double t;

        ele(){}
        ele(int _i, double _t){
             i = _i, t = _t;
        }

        bool operator<(const ele &A)const{
            if(t == A.t)return i < A.i;
            return t < A.t;
        }
};

int main(){

    int n;
    scanf("%d", &n);

    vector <ele> e(n);

    for(int i=1; i<=n; i++){
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        e[i-1] = {i, sqrt(x*x+y*y)/(double)v};
    }

    sort(e.begin(), e.end());
    for(int i=0; i<e.size(); i++)printf("%d\n", e[i].i);

}
