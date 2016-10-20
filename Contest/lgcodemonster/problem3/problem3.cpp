#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int x[100003], y[100003];

int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while(t--){

        int n, k, w;
        scanf("%d %d %d", &n, &k, &w);

        int mx = 2000000000, Mx = -2000000000;

        vector <int> Y, MPY;

        for(int i=1; i<=n; i++){
            scanf("%d %d", &x[i], &y[i]);
            mx = min(x[i], mx);
            Mx = max(x[i], Mx);
            Y.push_back(y[i]);
            MPY.push_back(y[i]-w);
            MPY.push_back(y[i]);
            MPY.push_back(y[i]+w);
        }

        sort(Y.begin(), Y.end());
        Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
        sort(MPY.begin(), MPY.end());
        MPY.resize(unique(MPY.begin(), MPY.end()) - MPY.begin());

        vector <int> dn(MPY.size()), ct(MPY.size());
        int lx = mx + w, rx = Mx - w;
        for(int i=1; i<=n; i++){
            int p = lower_bound(MPY.begin(), MPY.end(), y[i]) - MPY.begin();
            if(lx < x[i] && x[i] < rx)ct[p]++;
            dn[p]++;
        }

        for(int i=1; i<dn.size(); i++){
            dn[i] += dn[i-1];
            ct[i] += ct[i-1];
        }

        vector <int> PY(Y.size()), CY(Y.size()), NY(Y.size());
        for(int i=0; i<Y.size(); i++){
            NY[i] = lower_bound(MPY.begin(), MPY.end(), Y[i]+w) - MPY.begin();
            CY[i] = lower_bound(MPY.begin(), MPY.end(), Y[i]) - MPY.begin();
            PY[i] = lower_bound(MPY.begin(), MPY.end(), Y[i]-w) - MPY.begin();
        }

        bool pos = false;

        for(int i=0; i<Y.size() && !pos; i++){
            int bY = dn[CY[i]-1];
            for(int j=i+1; j<Y.size() && !pos; j++){
                int uY = dn.back() - dn[CY[j]];
                if(bY + uY <= k){
                    int mdY = ct[PY[j]-1] - ct[NY[i]];
                    if(bY+uY+mdY <= k)pos = true;
                }
            }
        }

        if(pos)printf("YES\n");
        else
            printf("NO\n");

    }

}
