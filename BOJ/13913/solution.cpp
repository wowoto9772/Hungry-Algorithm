#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class ele{
    public:
        int p, c;
        ele(){}
        ele(int _p, int _c){
            p = _p, c = _c;
        }
};

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    vector <int> chk(200003, 200003);
    vector <int> rev(200003, -1);

    queue < ele > q;
    chk[n] = 0;
    q.emplace(n, 0);

    while(!q.empty()){
        ele f = q.front(); q.pop();
        if(f.p == k){
            printf("%d\n", f.c);
            vector <int> ans;
            while(rev[f.p] != -1){
                ans.push_back(f.p);
                f.p = rev[f.p];
            }
            ans.push_back(f.p);
            reverse(ans.begin(), ans.end());
            for(auto &e : ans)printf("%d ", e);
            return 0;
        }
        f.c++;
        int v = 2;
        if(f.p && f.p*v <= 200000){
            if(chk[f.p*v] > f.c){
                chk[f.p*v] = f.c;
                rev[f.p*v] = f.p;
                q.emplace(f.p*v, f.c);
            }
        }
        if(f.p >= 0 && chk[f.p-1] > f.c){
            chk[f.p-1] = f.c;
            rev[f.p-1] = f.p;
            q.emplace(f.p-1, f.c);
        }
        if(f.p+1 <= 200000 && chk[f.p+1] > f.c){
            chk[f.p+1] = f.c;
            rev[f.p+1] = f.p;
            q.emplace(f.p+1, f.c);
        }
    }

}
