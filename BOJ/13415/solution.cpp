#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int e[100003], t[100003];

int main(){

    vector < pair<int,int> > stk;

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)scanf("%d", &e[i]);

    int q;
    scanf("%d", &q);

    while(q--){
        int u, d;
        scanf("%d %d", &u, &d);
        if(stk.empty()){
            stk.emplace_back(u, 1);
        }else{
            while(!stk.empty() && stk.back().first <= u){
                stk.pop_back();
            }
            stk.emplace_back(u, 1);
        }
        while(!stk.empty() && stk.back().first <= d){
            stk.pop_back();
        }
        stk.emplace_back(d, -1);
    }

    int v = stk.front().first;

    for(int i=1; i<=v; i++)t[i] = e[i];
    sort(t+1, t+1+v);

    int l = 1, r = v;
    int c = v;

    stk.emplace_back(0, 0);

    for(int i=0; i<stk.size()-1; i++){
        int d = stk[i].first - stk[i+1].first;
        if(stk[i].second == 1){
            while(d--){
                e[c] = t[r];
                r--, c--;
            }
        }else{
            while(d--){
                e[c] = t[l];
                l++, c--;
            }
        }
    }
    
    for(int i=1; i<=n; i++)printf("%d ", e[i]);

}
