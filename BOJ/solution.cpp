#include <cstdio>
 
using namespace std;
 
int P[5000003];
 
int isPrime(int n){
    if((n%2) == 0){
        return n == 2;
    }
    else{
        for(int i=3; i*i <= n; i+=2){
            if(n%i)continue;
            return 0;
        }
        return 1;
    }
}
 
int main(){
     
    for(int i=2; i<=5000000; i++)P[i] = -1;
     
    int n;
    while(scanf("%d", &n) == 1 && n){
         
        int ans = 0;
        for(int i=2; i<=n/2; i++){
            if(P[i] == -1)P[i] = isPrime(i);
            if(P[n-i] == -1)P[n-i] = isPrime(n-i);
            if(P[i] && P[n-i])ans++;
        }
        printf("%d\n", ans);
     
    }
 
}