#include <cstdio>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    int c = 0;

    for(int i=2; i<=n-4; i+=2){
        int r = n-i;
        for(int j=r-1; j>=1; j--){
            int k = r-j;
            if(j-k >= 2){
                c++;
            }
        }
    }

    printf("%d\n", c);

}
