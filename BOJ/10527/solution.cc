#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

char str[23];

int main(){
    
    int n;
    scanf("%d", &n);
    
    map <string, int> dom, kat;
    
    for(int i=0; i<n; i++){
        scanf("%s", str);
        dom[string(str)]++;
    }
    
    for(int i=0; i<n; i++){
        scanf("%s", str);
        kat[string(str)]++;
    }
    
    int ans = 0;
    
    for(auto &e : dom){
        ans += min(e.second, kat[e.first]);
    }
    
    printf("%d\n", ans);

}