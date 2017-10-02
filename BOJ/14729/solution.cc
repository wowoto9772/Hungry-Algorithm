#include <cstdio>
#include <queue>

using namespace std;

int main(){
    
    int n;
    scanf("%d", &n);
    
    priority_queue < double > q;
    
    for(int i=0; i<n; i++){
        double f;
        scanf("%lf", &f);
        if(q.size() < 7)q.push(f);
        else if(q.top() > f){
            q.pop();
            q.push(f);
        }
    }
    
    double e[7];
    for(int i=6; i>=0; i--){
        e[i] = q.top();q.pop();
    }
    
    for(int i=0; i<7; i++)printf("%.3lf\n", e[i]);

}