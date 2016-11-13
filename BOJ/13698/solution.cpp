#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[203];
int x[203], y[203];

int main(){

    scanf("%s", str);

    int s = strlen(str);

    x[1] = 1, y[4] = 1;
    for(int i=0; i<s; i++){
        if(str[i] == 'A')swap(x[1], x[2]), swap(y[1], y[2]);
        else if(str[i] == 'B')swap(x[1], x[3]), swap(y[1], y[3]);
        else if(str[i] == 'C')swap(x[1], x[4]), swap(y[1], y[4]);
        else if(str[i] == 'D')swap(x[2], x[3]), swap(y[2], y[3]);
        else if(str[i] == 'E')swap(x[2], x[4]), swap(y[2], y[4]);
        else{
            swap(x[3], x[4]), swap(y[3], y[4]);
        }
    }

    for(int i=1; i<=4; i++)if(x[i])printf("%d\n", i);
    for(int i=1; i<=4; i++)if(y[i])printf("%d\n", i);

}
