#include <cstdio>
#include <algorithm>
using namespace std;

int e[10003];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &e[i]);
    }

    sort(e, e+n);
    for(int q=0; q<=10000; q++){
        int k = 0;
        bool flag = true;
        for(int j=n-1; j>=0; j--){
            if(q <= e[j]){
                if(k == q){
                    if(e[j] <= q)break;
                    else{
                        flag = false;
                    }
                }
                k++;
            }
        }

        if(k == q && flag){
            printf("%d\n", q);
            return 0;
        }
    }

}
