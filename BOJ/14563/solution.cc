#include <cstdio>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        int c = 0;
        if(n != 1)c++;

        for(int i=2; i*i <= n; i++){
            if(n%i)continue;
            c += i;
            if(i < n/i)c += n/i;
        }

        if(c == n)printf("Perfect");
        else if(c < n)printf("Deficient");
        else
            printf("Abundant");
        printf("\n");
    }

}
