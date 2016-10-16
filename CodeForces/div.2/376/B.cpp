#include <cstdio>

using namespace std;

int a[200003];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }

    for(int i=1; i<=n; i++){
        int j = i+1;
        if(i < n){
            if(a[i]&1){
                a[i]--;
                a[j]--;
                if(a[j] < 0){
                    printf("NO\n");
                    return 0;
                }
            }
        }else{
            if(a[i]&1){
                printf("NO\n");
            }else{
                printf("YES\n");
            }
        }
    }
    
    return 0;

}
