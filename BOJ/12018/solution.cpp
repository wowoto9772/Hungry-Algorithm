#include <cstdio>
#include <functional>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    priority_queue < int, vector<int>, greater<int> > pq;

    for(int i=1; i<=n; i++){
        int c, p;
        scanf("%d %d", &c, &p);
        vector <int> v(c);
        for(int j=0; j<c; j++)scanf("%d", &v[j]);
        if(c<p)pq.push(1);
        else{
            sort(v.begin(), v.end());
            pq.push(v[c-p]);
        }
    }

    int ans = 0;
    while(!pq.empty() && m >= pq.top()  && pq.top() <= 36){
        m -= pq.top(); pq.pop();
        ans++;
    }

    printf("%d\n", ans);

}
