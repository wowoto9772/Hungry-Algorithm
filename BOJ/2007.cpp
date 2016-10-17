#include <cstdio>

#include <vector>

#include <algorithm>

using namespace std;

int e[103][103];

int main(){

    int n;
    scanf("%d", &n);

    vector <int> v(n*(n-1)/2);

    for(int i=0; i<v.size(); i++){
        scanf("%d", &v[i]);
    }

    if(n == 2){
        v.back()--;
        v.push_back(1);
        sort(v.begin(), v.end());
        printf("%d %d\n", v[0], v[1]);
        return 0;
    }

    sort(v.begin(), v.end());

    int top = 0;

    int tot = 0;

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            e[i][j] = v[top++];
            tot += e[i][j];
        }
    }

    tot >>= 1;

    vector <int> ans;

    for(int i=1; i<n-1; i++){
        ans.push_back(e[i][i+2] + e[i][i+1] - e[i+1][i+2]);
        ans.back() /= 2;
    }

    ans.push_back(e[n-2][n-1] - ans.back());

    for(int i=0; i<ans.size(); i++)tot -= ans[i];

    ans.push_back(tot);

    sort(ans.begin(), ans.end());

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(e[i][j] != ans[i-1] + ans[j-1]){
                printf("Impossible\n");
                return 0;
            }
        }
    }

    for(int i=0; i<ans.size(); i++)printf("%d ", ans[i]);

}
