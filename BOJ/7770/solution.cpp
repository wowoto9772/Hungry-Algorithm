#include <cstdio>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    long long a = 0;
    int d = 1;

    for(int h = 1;; h++){
        a += d;
        if(a == n){
            printf("%d\n", h);
            return 0;
        }else if(a > n){
            printf("%d\n", h-1);
            return 0;
        }
        d += h*4;
    }

}

// 1 5 13 25 
