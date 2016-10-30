#include <cstdio>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string s[500003];
char str[13];

int main(){

    int k, l;
    scanf("%d %d", &l, &k);

    map <string, int> v;

    for(int i=1; i<=k; i++){
        scanf("%s", str);
        s[i] = string(str);
        v[s[i]] = i;
    }

    for(int i=1; i<=k; i++){
        if(v[s[i]] == i){
            printf("%s\n", s[i].c_str());
            l--;
            if(l == 0)break;
        }
    }

}
