#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int x[53], y[53];

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    scanf("%d", &t);

    while(t--){

        int n, k, w;
        scanf("%d %d %d", &n, &k, &w);

        int mx = 2000000000, Mx = -2000000000;

        vector <int> Y;

        for(int i=1; i<=n; i++){
            scanf("%d %d", &x[i], &y[i]);
            mx = min(x[i], mx);
            Mx = max(x[i], Mx);
            Y.push_back(y[i]);
        }

        sort(Y.begin(), Y.end());

        Y.resize(unique(Y.begin(), Y.end()) - Y.begin());

        int lx = mx + w, rx = Mx - w;

        bool pos = false;

        for(int i=0; i<Y.size() && !pos; i++){
            int ly = Y[i] + w;
            for(int j=i+1; j<Y.size() && !pos; j++){
                int ry = Y[j] - w;

                bool flag = false;

                int _k = 0;
                for(int e=1; e<=n; e++){
                    if(lx < x[e] && x[e] < rx && ly < y[e] && y[e] < ry){
                        _k++;
                    }else if(y[e] < Y[i] || Y[j] < y[e]){
                        _k++;
                    }
                }

                if(_k <= k)pos = true;
            }
        }

        if(pos)printf("YES\n");
        else
            printf("NO\n");

    }

}
