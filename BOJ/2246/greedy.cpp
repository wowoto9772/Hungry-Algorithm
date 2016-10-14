#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    vector < pair<int,int> > v(n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &v[i].first, &v[i].second);
    }

    sort(v.begin(), v.end());

    int ans = 1, le = v[0].second;

    for(int i=0; i<v.size(); i++){
        if(le <= v[i].second)continue;
        ans++;
        le = v[i].second;
    }

    printf("%d\n", ans);
}
