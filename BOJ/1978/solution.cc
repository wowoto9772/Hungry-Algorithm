#include <cstdio>

using namespace std;

bool p[1003] = {true, true};

int main(){
    
    for(int i=2; i*i <= 1000; i++){
        if(!p[i]){
            for(int j=i*i; j<=1000; j+=i)p[j] = true;
        }
    }
    
    int n;
    scanf("%d", &n);
    
    int c = 0;
    for(int i=1; i<=n; i++){
        int a;
        scanf("%d", &a);
        if(!p[a])c++;
    }
    printf("%d\n", c);
}
