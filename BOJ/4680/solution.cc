#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int e[13];

int main(){

    int v, n;
    while(scanf("%d %d", &v, &n) == 2){
        
        if(n == 0)break;

        printf("Sums of %d:\n", v);

        for(int i=0; i<n; i++){
            scanf("%d", &e[i]);
        }

        vector < vector <int> > ans;
        for(int i=1; i<(1<<n); i++){
            int c = 0;
            vector <int> k;
            for(int j=0; j<n; j++){
                if(i & (1<<j)){
                    k.push_back(-e[j]);
                    c += e[j];
                }
            }
            if(c == v){
                ans.emplace_back(k);
            }
        }

        if(ans.empty())printf("NONE\n");
        else{
            sort(ans.begin(), ans.end());
            ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
            for(auto &x : ans){
                for(int i=0; i<x.size(); i++){
                    if(i)printf("+");
                    printf("%d", -x[i]);
                }
                printf("\n");
            }
        }
    }

}
