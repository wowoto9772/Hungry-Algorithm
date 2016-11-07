#include <cstdio>
#include <queue>

using namespace std;

class ele{
    public:
        int p, c;
        ele(){}
        ele(int _p, int _c){
            p = _p, c = _c;
        }
        bool operator<(const ele &A)const{
            return c > A.c;
        }
};

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    vector <int> chk(200003, 200003);

    priority_queue < ele > q;
    chk[n] = 0;
    q.emplace(n, 0);

    while(!q.empty()){
        ele f = q.top(); q.pop();
        if(chk[f.p] < f.c)continue;
        if(f.p == k){
            printf("%d\n", f.c);
            return 0;
        }
        int v = 1;
        while(f.p && f.p*v <= 100000){
            v <<= 1;
            if(chk[f.p*v] <= f.c)continue;
            else{
                chk[f.p*v] = f.c;
                q.emplace(f.p*v, f.c);
            }
        }
        if(f.p > 0 && chk[f.p-1] > f.c+1){
            chk[f.p-1] = f.c+1;
            q.emplace(f.p-1, f.c+1);
        }
        if(f.p+1 <= 200000 && chk[f.p+1] > f.c+1){
            chk[f.p+1] = f.c+1;
            q.emplace(f.p+1, f.c+1);
        }
    }

}
