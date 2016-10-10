#include <cstdio>
#include <algorithm>

using namespace std;

int cnt[100003];

int main(){

    int n;
    scanf("%d", &n);

    vector < pair<int,int> > v(n<<1);

    for(int i=0; i<n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        v[i*2] = {x, i};
        v[i*2+1] = {y, i};
    }

    sort(v.begin(), v.end());

    int L;
    scanf("%d", &L);

    int l = 0, z = 0;

    int ans = 0;

    for(int r=0; r<v.size(); r++){

        int p = v[r].second;
        cnt[p]++;
        if(cnt[p] == 2)z++;

        while(v[l].first < v[r].first - L){
            int q = v[l].second;
            cnt[q]--;
            if(cnt[q] == 1)z--;
            l++;
        }

        ans = max(ans, z);

    }

    printf("%d\n", ans);

}
