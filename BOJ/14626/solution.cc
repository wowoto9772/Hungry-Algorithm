#include <cstdio>

char str[17];

int main(){

    scanf("%s", str);
    int j;
    int v = 0;

    for(int i=0; i<13; i++){
        if(str[i] == '*'){
            j = i;
        }else{
            v += ((i&1) ? 3 : 1) * (str[i] - '0');
        }
    }

    v %= 10;
    for(int i=0; i<10; i++){
        if((v + ((j&1) ? 3 : 1) * i) % 10 == 0){
            printf("%d\n", i);
            break;
        }
    }

}
