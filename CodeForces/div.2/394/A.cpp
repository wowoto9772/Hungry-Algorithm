#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    
    int a, b;
    scanf("%d %d", &a, &b);
    
    if(a+b > 0 && abs(a-b) <= 1)printf("YES");
    else
        printf("NO");

}