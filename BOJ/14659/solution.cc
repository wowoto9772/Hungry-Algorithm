#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main(){
    
    int n;
    scanf("%d", &n);
    
    stack < pair<int,int> > v;
    
    int ans = 0;
    
    for(int i=1; i<=n; i++){
        int x;
        scanf("%d", &x);
        while(!v.empty() && v.top().first <= x){
            int p = i - v.top().second - 1;
            if(ans < p)ans = p;
            v.pop();
        }
        v.emplace(x, i);
    }
    
    while(!v.empty()){
        int q = n - v.top().second;
        if(ans < q)ans = q;
        v.pop();
    }
    
    printf("%d\n", ans);

}