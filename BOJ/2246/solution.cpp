#include <cstdio>
#include <vector>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    vector < pair<int,int> > v(n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &v[i].first, &v[i].second);
    }

    int ans = 0;

    for(int i=0; i<v.size(); i++){
        bool flag = false;
        for(int j=0; j<n && !flag; j++){
            if(v[j].first < v[i].first){ // near
                if(v[j].second <= v[i].second)flag = true;
            }
            if(v[j].second < v[i].second){ // cheap
                if(v[j].first <= v[i].first)flag = true;
            }        
        }
        ans += !flag;
    }

    printf("%d\n", ans);
}
