#include <stdio.h>

#include <limits.h>

#include <queue>

#include <vector>

#include <algorithm>

using namespace std;

using ll = long long;

int n, k;

int c[100003];

bool pos(vector <int> in, const vector < vector <int> > &par, const vector < vector <int> > &son, ll limit){

    for(int i=1; i<=n; i++){

        if(c[i] > limit)return false;

    }

    queue <int> q;

    vector <ll> d(n+1);

    int x = 0;

    for(int i=1; i<=n; i++){

        d[i] = c[i];

        if(in[i] == 0){
            q.push(i);
        }

    }

    while(!q.empty()){

        int f = q.front(); q.pop();

        for(int i=0; i<par[f].size(); i++){

            int g = par[f][i];

            in[g]--;

            if(in[g] == 0){

                q.push(g);

                vector < pair<ll,int> > choice;

                for(int j=0; j<son[g].size(); j++){
                    int _son = son[g][j];
                    choice.emplace_back(d[_son], _son);
                }

                sort(choice.begin(), choice.end());

                for(const auto & v : choice){

                    if(d[g] + v.first <= limit){
                        d[g] += v.first;
                    }else{
                        x++;
                    }

                }

            }

        }

    }

    return x <= k;

}

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        scanf("%d %d", &n, &k);

        for(int i=1; i<=n; i++)scanf("%d", &c[i]);

        vector < vector <int> > lnk;

        lnk.resize(n+1);

        vector <int> _in(n+1);

        for(int i=1; i<n; i++){

            int a, b;
            scanf("%d %d", &a, &b);

            lnk[a].push_back(b);
            lnk[b].push_back(a);

            _in[b]++;
            _in[a]++;

        }

        int root = -1;
        
        for(int i=1; i<=n; i++){

            if(_in[i] == 1){
                
                root = i;

                break;

            }

        }

        // graph remodeling

        queue < int > q;

        vector < int > in(n+1);
        vector < bool > used(n+1);
        vector < vector <int> > par, son;

        par.resize(n+1);
        son.resize(n+1);

        used[root] = true;
        q.push(root);

        while(!q.empty()){

            int f = q.front(); q.pop();

            for(int i=0; i<lnk[f].size(); i++){

                int g = lnk[f][i];

                if(used[g])continue;

                used[g] = true;

                in[f]++;

                par[g].push_back(f);
                son[f].push_back(g);

                q.push(g);

            }

        }

        ll ans = LLONG_MAX;

        ll l = 1, r = 1000000000000003LL, m;

        while(l <= r){

            m = (l+r) / 2LL;

            if(pos(in, par, son, m)){
                ans = min(ans, m);
                r = m - 1;
            }else{
                l = m + 1;
            }

        }

        printf("%lld\n", ans);

    }

}
