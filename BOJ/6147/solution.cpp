#include <cstdio>
#include <algorithm>

using namespace std;

int c[20003];

int main(){

    int n, b;
    scanf("%d %d", &n, &b);

    for(int i=0; i<n; i++)scanf("%d", &c[i]);

    sort(c, c+n);

    for(int i=n-1; i>=0; i--){
        b -= c[i];
        if(b <= 0){
            printf("%d\n", n-i);
            return 0;
        }
    }

}
