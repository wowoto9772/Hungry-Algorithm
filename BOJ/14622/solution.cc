#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
using ll = long long;

bool isPrime(int v){
    if(v < 2)return false;
    else if(v == 2)return true;
    else if((v&1) == 0)return false;
    else{
        for(int i=3; i*i <= v; i+=2){
            if(v%i)continue;
            return false;
        }
        return true;
    }
}

bool called[5000003];

int main(){
    
    int n;
    scanf("%d", &n);
    
    priority_queue < int, vector <int>, greater <int> > p, q;
    
    ll P = 0, Q = 0;    
    
    for(int i=1; i<=n; i++){
        
        int a, b;
        scanf("%d %d", &a, &b);
        
        if(isPrime(a)){
            if(called[a])P -= 1000;
            else{
                called[a] = true;
                p.push(a);
                if(p.size() > 3)p.pop();
            }
        }
        else{
            if(q.size() < 3)Q += 1000;
            else
                Q += q.top();
        }
        
        if(isPrime(b)){
            if(called[b])Q -= 1000;
            else{
                called[b] = true;
                q.push(b);
                if(q.size() > 3)q.pop();
            }
        }
        else{
            if(p.size() < 3)P += 1000;
            else
                P += p.top();
        }
    }
    
    if(P > Q)printf("소수의 신 갓대웅");
    else if(P < Q)printf("소수 마스터 갓규성");
    else
        printf("우열을 가릴 수 없음");

}