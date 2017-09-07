#include <cstdio>
#include <cstring>

using namespace std;

char str[100003];

int main(){

    int a, b;
    while(scanf("%s %d %d", str, &a, &b) == 3){
        if(strcmp(str, "#") == 0 && !a && !b)break;
        printf("%s ", str);
        if(a > 17 || b >= 80)printf("Senior");
        else
            printf("Junior");
        puts("");
    }

}