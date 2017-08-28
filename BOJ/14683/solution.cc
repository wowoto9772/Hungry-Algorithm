#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

    int a, b, x, y;
    scanf("%d %d %d %d", &a, &b, &x, &y);
    
    int c = abs(a-x) + abs(b-y);
    
    int k;
    scanf("%d", &k);
    
    if(c > k || (c&1) != (k&1))puts("N");
    else
        puts("Y");

}