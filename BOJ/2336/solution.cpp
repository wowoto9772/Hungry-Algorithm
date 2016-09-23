#include <stdio.h>

#include <algorithm>

#include <vector>

using namespace std;

class BIT{
    public:

        vector <int> T;
        int S;

        BIT(const int n){
            S = n;
            T.resize(S + 1);
        }

        void Update(int p, int v){
            while (p > 0){
                T[p] = max(T[p], v);
                p -= p & (-p);
            }
        }

        int Query(int p){
            int ret = 0;
            while (p <= S){
                ret = max(ret, T[p]);
                p += p & (-p);
            }return ret;
        }

};

class ele{
    public:
        int a, b, c;
        bool operator<(const ele &A)const{
            if(a == A.a){
                if(b == A.b)return c < A.c;
                return b < A.b;
            }
            return a < A.a;
        }
}e[500003];

int main(){

    int n, y;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &y);
        e[y].a = n - i + 1;
    }
    for(int i=1; i<=n; i++){
        scanf("%d", &y);
        e[y].b = n - i + 1;
    }
    for(int i=1; i<=n; i++){
        scanf("%d", &y);
        e[y].c = n - i + 1;
    }

    sort(e+1, e+1+n);

    BIT tree(n);

    int x = 0;

    for(int i=n; i>=1; i--){

        x += tree.Query(e[i].b) < e[i].c;

        tree.Update(e[i].b, e[i].c);

    }

    printf("%d\n", x);

}
