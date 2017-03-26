#include <cstdio>
#include <algorithm>

using namespace std;

int a[13], b[13];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)scanf("%d %d", &a[i], &b[i]);

    int ans = 1000000003;

    for(int i=1; i<(1<<n); i++){
        int A = 1, B = 0;
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                A *= a[j], B += b[j];
            }
        }
        ans = min(ans, abs(A-B));
    }

    printf("%d\n", ans);

}
