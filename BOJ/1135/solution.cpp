#include <stdio.h>
 
#include <vector>
 
#include <algorithm>
 
using namespace std;
 
vector < vector <int> > lnk;
vector < int > dp;
 
int dy(int c){
 
    if(dp[c] != -1)return dp[c];
 
    dp[c] = 0;
 
    vector <int> p;
 
    for(int i=0; i<lnk[c].size(); i++)p.push_back(1 + dy(lnk[c][i]));
 
    sort(p.begin(), p.end());
 
    if(!p.empty()){
        int a = 0;
        for(int j=p.size()-1; j>=0; j--){
            dp[c] = max(dp[c], p[j] + a);
            a++;
        }
    }
 
    return dp[c];
 
}
 
int main(){
 
    int n;
    scanf("%d", &n);
 
    lnk.resize(n);
    dp.resize(n);
 
    for(int i=0; i<n; i++){
 
        int p;
        scanf("%d", &p);
 
        dp[i] = -1;
 
        if(p == -1)continue;
 
        lnk[p].push_back(i);
 
    }
 
    printf("%d\n", dy(0));
 
}
