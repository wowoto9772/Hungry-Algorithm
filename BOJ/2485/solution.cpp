#include <cstdio>
#include <limits.h>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    int m = 1;
    while(m){
        m = a % b;
        a = b;
        b = m;
    }
    return a;
}

int p[100003];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)scanf("%d", &p[i]);

    sort(p+1, p+1+n);

    int g = gcd(p[2]-p[1], p[3]-p[2]);

    for(int i=4; i<=n; i++){
        g = gcd(g, p[i]-p[i-1]);
    }

    int ans = INT_MAX;

    for(int i=1; i*i <= g; i++){

        if(g%i)continue;

        int c = 0;
        for(int j=1; j<n; j++){
            int k = p[j+1] - p[j] - i;
            c += (k) / i;
        }
        ans = min(ans, c);

        if(i >= g/i)break;

        c = 0;
        for(int j=1; j<n; j++){
            int k = p[j+1] - p[j] - (g/i);
            c += (k) / (g/i);
        }
        ans = min(ans, c);
    }

    printf("%d\n", ans);

}
