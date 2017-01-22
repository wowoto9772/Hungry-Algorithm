#include <cstdio>

using namespace std;

int v[1003];

int main(){
    int n, k, d;
    scanf("%d %d %d", &n, &k, &d);
    int f = n-1;
    for(int i=1; i<=d; i++)f /= k;
    if(f)printf("-1\n");
    else{
        for(int i=0; i<n; i++){
            v[i] = i;
        }
        for(int i=0; i<d; i++){
            for(int j=0; j<n; j++){
                printf("%d ", (v[j] % k) + 1);
                v[j] /= k;
            }printf("\n");
        }
    }
}
