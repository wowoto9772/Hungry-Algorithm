#include <cstdio>
#include <algorithm>

using namespace std;

double e[103];

int main(){
    
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)scanf("%lf", &e[i]);
    sort(e, e+n);
    
    printf("%.2lf\n", e[1]);

}