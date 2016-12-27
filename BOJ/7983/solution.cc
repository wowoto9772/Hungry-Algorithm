#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector < pair<int,int> > dat;

int main(){

    int n;
    scanf("%d", &n);
    dat.resize(n);

    for(int i=0; i<n; i++){
        int d, t;
        scanf("%d %d", &d, &t);
        dat[i] = {t, d};
    }

    sort(dat.begin(), dat.end());

    int ans = 1000000000;

    for(int i=n-1; i>=0; i--){
        int ed = min(ans, dat[i].first);
        ans = ed - dat[i].second;
    }

    printf("%d\n", ans);

}
