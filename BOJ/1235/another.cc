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
    sort(e, e+n);

    int m = 1;

    for(int i=0; i<n-1; i++){
        while(e[i].substr(0, m) == e[i+1].substr(0, m))m++;
    }

    printf("%d\n", m);

}
