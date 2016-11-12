#include <cstdio>

using namespace std;

int e[100003];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<n; i++){
        e[i] = i+1;
        int j = i;
        while(j >= 2){
            int k = j >> 1;
            int x = e[j];
            e[j] = e[k];
            e[k] = x;
            j = k;
        }
    }

    for(int i=1; i<n; i++)printf("%d ", e[i]);
    printf("1\n");

}
