#include <cstdio>

using namespace std;

int a[10], b[10];

int main(){

    int x = 0, y = 0;

    for(int i=0; i<9; i++)scanf("%d", &a[i]);
    for(int i=0; i<9; i++)scanf("%d", &b[i]);

    int z = 0;

    for(int i=0; i<9; i++){
        x += a[i];
        if(x > y)z++;
        y += b[i];
    }

    if(z)printf("Yes\n");
    else
        printf("No\n");

}
