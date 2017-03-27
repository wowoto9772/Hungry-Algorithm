#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

    int n, l;
    scanf("%d %d", &n, &l);

    vector < pair<int,int> > lnk(n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &lnk[i].first, &lnk[i].second);
        lnk[i].second--;
    }

    int ri = -1;

    int ans = 0;

    sort(lnk.begin(), lnk.end());
    for(int i=0; i<n; i++){
        if(ri < lnk[i].first){
            int d = (lnk[i].second - lnk[i].first + 1);
            int s = d/l;
            if(d%l)s++;
            ans += s;
            ri = lnk[i].first + s*l - 1;
        }else{
            int d = (lnk[i].second - ri);
            int s = d/l;
            if(d < 0)continue;
            if(d%l)s++;
            ans += s;
            ri = ri + s*l;
        }
    }

    printf("%d\n", ans);

}
