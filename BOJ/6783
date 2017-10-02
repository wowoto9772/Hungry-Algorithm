#include <cstdio>
#include <cstring>

using namespace std;

char str[1003];

int droot(int v){
    if(v < 10)return v;
    else{
        int r = 0;
        while(v){
            r = r + v % 10;
            v /= 10;
        }
        return droot(r);
    }
}

int main(){

    while(scanf("%s", str) == 1){

        if(!strcmp(str, "0"))break;

        int s = strlen(str);

        int v = 0;

        for(int i=0; i<s; i++){
            v = v + str[i] - '0';
        }

        printf("%d\n", droot(v));

    }

}
