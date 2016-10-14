#include <cstdio>
#include <cmath>
#include <algorithm>

using ll = long long;
using namespace std;

int bucket;

inline int getID(int l, int r){
    return (l/bucket)*bucket + (r/bucket);
}

class ele{
    public:
        int l, r, id, q;
        ll ret;
}q[100003];

int e[100003], d[1000003];

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    bucket = (int)sqrt(n+1e-9);

    for(int i=0; i<n; i++)scanf("%d", &e[i]);

    for(int i=0; i<m; i++){
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].l--, q[i].r--;
        q[i].id = getID(q[i].l, q[i].r);
        q[i].q = i;
    }

    sort(q, q+m, [](const ele &A, const ele &B){
            return A.id < B.id;
            });

    for(int i=0; i<m; i++){
        if(i == 0){
            q[i].ret = 0;
            for(int j=q[i].l; j<=q[i].r; j++){
                q[i].ret += (ll)(2*(d[e[j]]++)+1)*(ll)e[j];
            }
        }
        else{
            q[i].ret = q[i-1].ret;
            if(q[i-1].r < q[i].r){
                for(int j=q[i-1].r+1; j<=q[i].r; j++){
                    q[i].ret += (ll)(2*(d[e[j]]++)+1)*(ll)e[j];
                }
            }
            if(q[i].l < q[i-1].l){
                for(int j=q[i].l; j<q[i-1].l; j++){
                    q[i].ret += (ll)(2*(d[e[j]]++)+1)*(ll)e[j];
                }
            }
            if(q[i].l > q[i-1].l){
                for(int j=q[i-1].l; j<q[i].l; j++){
                    q[i].ret -= (ll)(2*(d[e[j]]--)-1)*(ll)e[j];  
                }
            }
            if(q[i-1].r > q[i].r){
                for(int j=q[i].r+1; j<=q[i-1].r; j++){
                    q[i].ret -= (ll)(2*(d[e[j]]--)-1)*(ll)e[j];  
                }
            }

        }
    }

    sort(q, q+m, [](const ele &A, const ele &B){
            return A.q < B.q; 
            });

    for(int i=0; i<m; i++)printf("%lld\n", q[i].ret);

}
