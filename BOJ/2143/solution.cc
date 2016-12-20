#include <cstdio>
#include <algorithm>

using namespace std;

int A[1003], B[1003];
int c[1000003];

int main(){

    int t;
    scanf("%d", &t);

    int a, b;
    scanf("%d", &a);

    for(int i=1; i<=a; i++){
        scanf("%d", &A[i]);
        A[i] += A[i-1];
    }

    scanf("%d", &b);
    
    for(int i=1; i<=b; i++){
        scanf("%d", &B[i]);
        B[i] += B[i-1];
    }

    int top = 0;

    for(int i=1; i<=b; i++){
        for(int j=i; j<=b; j++){
            c[top++] = B[j] - B[i-1];
        }
    }

    sort(c, c+top);

    long long ans = 0;

    for(int i=1; i<=a; i++){
        for(int j=i; j<=a; j++){
            int v = A[j] - A[i-1];
            int goal = t-v;
            int p = lower_bound(c, c+top, goal) - c;
            int q = upper_bound(c, c+top, goal) - c;
            q--;
            ans += max(q-p+1, 0);
        }
    }

    printf("%lld\n", ans);

}
