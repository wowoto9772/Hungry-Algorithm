#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int c[200003];

int main(){
   
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for(int i=1; i<=n; i++)scanf("%d", &c[i]);

    vector < vector <int> > lnk;
    lnk.resize(n+1);

    for(int i=1; i<=m; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }

    vector <bool> chk(n+1);

    int ans = 0;

    for(int i=1; i<=n; i++){
        if(chk[i])continue;

        queue <int> q;
        chk[i] = true;
        q.push(i);

        vector <int> color;

        while(!q.empty()){
            int f = q.front(); q.pop();
            color.push_back(c[f]);
            for(int j=0; j<lnk[f].size(); j++){
                int g = lnk[f][j];
                if(chk[g])continue;
                chk[g] = true;
                q.push(g);
            }
        }

        sort(color.begin(), color.end());

        int tot = color.size();

        int x = -1, y = 0;
        int tmp = 0;

        for(int j=0; j<color.size(); j++){
            if(color[j] == x)y++;
            else{
                tmp = max(tmp, y);
                x = color[j];
                y = 1;
            }
        }

        tmp = max(tmp, y);

        ans += (tot - tmp);

    }

    printf("%d\n", ans);

    return 0;

}
