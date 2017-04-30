#include <cstdio>

using namespace std;

double e[53];

int main(){

    int t;
    scanf("%d", &t);

    int tc = 0;

    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        double x;
        scanf("%lf", &x);

        for(int i=0; i<n; i++)scanf("%lf", &e[i]);
        double l = 0, r = 1.0, m;
        double c = 0;
        while(r-l > 1e-9){
            m = (l+r) / 2;
            double y = 0;
            for(int i=0; i<n; i++){
                if(m > e[i])y += m - e[i];
            }
            if(y > x)r = m;
            else{
                c = m;
                l = m;
            }
        }
        printf("Case #%d: ", ++tc);
        double ans = 1.0;
        for(int i=0; i<n; i++){
            if(c > e[i])e[i] = c;
            ans *= e[i];
        }
        printf("%lf\n", ans);
    }

}
