#include <cstdio>

using namespace std;

int gcd(int a, int b){
    int m = 1;
    while(m){
        m = a % b;
        a = b;
        b = m;
    }return a;
}

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        scanf("%d", &n);

        if(n == 1)printf("1\n");
        else{

            int ans = 0;
            for(int i=1; i*i <= n; i++){
                if(n%i)continue;
                int a = i, b = n / i;
                if(a < b){
                    if(gcd(a,b) == 1)ans++;
                }else{
                    break;
                }
            }
            printf("%d\n", ans);

        }

    }

}
