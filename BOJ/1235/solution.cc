#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

char str[103];
string e[1003];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s", str);
        e[i] = string(str);
        reverse(e[i].begin(), e[i].end());
    }

    int l = 1, r = strlen(str), m;
    int ans = n;
    while(l <= r){
        m = (l+r) / 2;
        set <string> st;
        for(int i=0; i<n; i++)st.insert(e[i].substr(0, m));
        if(st.size() == n){
            r = m - 1;
            ans = m;
        }else{
            l = m + 1;
        }
    }

    printf("%d\n", ans);

}
