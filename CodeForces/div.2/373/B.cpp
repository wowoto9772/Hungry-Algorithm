#include <cstdio>

#include <algorithm>

using namespace std;

char str[100003];

int main(){

    int n;
    scanf("%d", &n);

    scanf("%s", str);

    char *p = {"rb"};

    int a = 0, b = 0, f = 0;
    int red = 0, black = 0;

    for(int i=0; i<n; i++){
        if(str[i] != p[f]){
            a++;
            if(str[i] == 'r')red++;
            else
                black++;
        }
        f ^= 1;
    }

    a -= min(red, black);

    f = 1;

    red = black = 0;

    for(int i=0; i<n; i++){
        if(str[i] != p[f]){
            b++;
            if(str[i] == 'r')red++;
            else
                black++;
        }
        f ^= 1;
    }

    b -= min(red, black);

    printf("%d\n", min(a, b));
    return 0;

}
