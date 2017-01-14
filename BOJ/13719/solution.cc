#include <cstdio>

using ll = long long;
using namespace std;

ll e[1000003];

int main(){

    int n;
    scanf("%d", &n);

    int l = 1, r = n;
    int c = 0;

    for(int i=1; i<=n; i++)scanf("%d", &e[i]);

    while(l <= r){
        if(e[l] < e[r]){
            e[l+1] += e[l];
            l++;
            c++;
        }else if(e[l] > e[r]){
            e[r-1] += e[r];
            r--;
            c++;
        }else{
            l++, r--;
        }
    }

    printf("%d\n", c);

}
