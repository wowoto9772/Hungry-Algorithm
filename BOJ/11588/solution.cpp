#include <cstdio>
#include <vector>

using namespace std;

bool cant[23][23];

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        cant[--a][--b] = true;
        cant[b][a] = true;
    }

    int ans = 0;

    for(int i=0; i<(1<<n); i++){
        vector <int> p;
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                p.push_back(j);
            }
        }
        bool flag = false;
        for(int j=0; j<p.size() && !flag; j++){
            for(int k=j+1; k<p.size() && !flag; k++){
                if(cant[p[j]][p[k]])flag = true;
            }
        }
        ans += !flag;
    }

    printf("%d\n", ans);

}
