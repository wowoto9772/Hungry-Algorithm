#include <stdio.h>

#include <set>

#include <algorithm>

using namespace std;

int e[1003];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){

        scanf("%d", &e[i]);

    }
    
    sort(e+1, e+1+n);

    set <int> my;

    for(int i=1; i<=n; i++)for(int j=i; j<=n; j++)my.insert(e[i]+e[j]);

    for(int i=n; i>=1; i--){
        for(int j=i-1; j>=1; j--){
            int t = e[i] - e[j];
            set <int> :: iterator it = my.lower_bound(t);
            if(it != my.end() && *it == t){
                printf("%d\n", e[i]);
                return 0;
            }
        }
    }

}
