#include <cstdio>

using namespace std;

char str[23];

int main(){

    scanf("%s", str);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i == 1 && j == 1){
                printf(":%s:", str);
            }else
                printf(":fan:");
        }printf("\n");
    }

}
