#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    vector < pair <int,int > > e(n);

    for(int i=0; i<n; i++){
        scanf("%d", &e[i].first);
        e[i].second = i+1;
    }

    sort(e.begin(), e.end());

    while(m--){
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);

        for(auto &x : e){
            if(a <= x.second && x.second <= b){
                if(--k == 0){
                    printf("%d\n", x.first);
                    break;
                }
            }
        }
    }

}
