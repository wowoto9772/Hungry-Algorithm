#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[18], c[5][100];

int type;

void out(char w, int h){

    c[2][h] = w;
    
    for(int i=-2; i<=2; i++){
        for(int j=-2; j<=2; j++){
            if(abs(i) + abs(j) == 2){
                c[2+i][h+j] = type;
            }
        }
    }

}

int main(){

    scanf("%s", str);

    int s = strlen(str);

    for(int i=0; i<5; i++)for(int j=0; j<=4*s; j++)c[i][j] = '.';

    type = '#';
    for(int i=0; i<s; i++)out(str[i], 4*i+2);

    type = '*';
    for(int i=2; i<s; i+=3)out(str[i], 4*i+2);

    for(int i=0; i<5; i++)printf("%s\n", c[i]);

}
