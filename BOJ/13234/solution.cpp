#include <cstdio>
#include <cstring>

using namespace std;

char str[8];

int main(){

    scanf("%s", str);

    int a = 0, b = 0;

    if(str[0] == 't')a++;

    scanf("%s", str);

    int t = 0;

    if(str[0] == 'A')t++;

    scanf("%s", str);

    if(str[0] == 't')b++;

    if(t == 1)a &= b;
    else
        a |= b;
    
    printf("%s\n", (a) ? "true" : "false");

}
