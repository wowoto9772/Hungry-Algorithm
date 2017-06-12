#include <cstdio>
#include <cstring>

using namespace std;

char c[104];

int main(){
    
    int a, b;
    scanf("%d %d %s", &a, &b, c);
    
    int s = strlen(c);
    
    if((c[s-1] - '0') & 1)c[s-1] = 1;
    else
        c[s-1] = 0;
    
    if(c[s-1])a^=b;
    
    printf("%d\n", a);
    
}