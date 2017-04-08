#include <cstdio>
#include <cstring>

using namespace std;

char str[100003];

int main(){

    while(scanf("%s", str) == 1){
        if(strcmp("0", str) == 0)break;
        int s = strlen(str);
        bool palin = true;
        for(int i=0; i<s/2 && palin; i++){
            palin &= str[i] == str[s-1-i];
        }
        if(palin)printf("yes\n");
        else
            printf("no\n");
    }

}
