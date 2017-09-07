#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int n, q;
    scanf("%d %d", &n, &q);
    
    vector <int> my;
    while(n--){
        int v;
        scanf("%d", &v);
        my.push_back(v);
    }
    
    my.push_back(1000000007);
    sort(my.begin(), my.end());
    
    while(q--){
        int a, b;
        scanf("%d %d", &a, &b);
        
        int l = lower_bound(my.begin(), my.end(), a) - my.begin();
        vector<int> ::iterator ri = lower_bound(my.begin(), my.end(), b);
        if(*ri != b)ri--;
        int r = ri - my.begin();
        
        int v = r-l+1; //ri - le + 1;
        if(v < 0)v = 0;
        
        printf("%d\n", v);
        
    }
    
}