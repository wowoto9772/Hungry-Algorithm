#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    vector <int> e(n);
    for(int i=0; i<n; i++)scanf("%d", &e[i]);
    sort(e.begin(), e.end());
    e.resize(unique(e.begin(), e.end()) - e.begin());

    int ans = e.back() - e[0];

    for(int i=0; i<e.size()-1; i++){
        e[i] = e[i+1] - e[i];
    }

    k--;

    e.pop_back();
    sort(e.begin(), e.end());
    while(!e.empty() && k){
        ans -= e.back();
        k--;
        e.pop_back();
    }

    printf("%d\n", ans);

}
