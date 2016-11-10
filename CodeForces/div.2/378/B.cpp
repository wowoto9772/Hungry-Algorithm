#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int l[100003], r[100003];

int main(){

    int n;
    scanf("%d", &n);

    int L = 0, R = 0;

    for(int i=1; i<=n; i++){
        scanf("%d %d", &l[i], &r[i]);
        L += l[i];
        R += r[i];
    }

    int x = 0, y = abs(L-R);

    for(int i=1; i<=n; i++){
        L = L - l[i] + r[i];
        R = R + l[i] - r[i];
        if(abs(L-R) > y){
            x = i;
            y = abs(L-R);
        }
        L = L + l[i] - r[i];
        R = R - l[i] + r[i];
    }

    printf("%d\n", x);

}
