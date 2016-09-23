#include <cstdio>

#include <cstring>

using namespace std;

char k[4], s[4], cmd[4];

int main(){

    scanf("%s %s", k, s);

    int n;
    scanf("%d", &n);

    while(n--){

        scanf("%s", cmd);

        int dx = 0, dy = 0;

        if(cmd[0] == 'L'){
            dx = -1;
            if(cmd[1] == 'B')dy = -1;
            else if(cmd[1] == 'T')dy = 1;
        }
        else if(cmd[0] == 'R'){
            dx = 1;
            if(cmd[1] == 'B')dy = -1;
            else if(cmd[1] == 'T')dy = 1;
        }
        else if(cmd[0] == 'B')dy = -1;
        else
            dy = 1;

        if(k[0]+dx < 'A' || k[0]+dx > 'H')continue;
        if(k[1]+dy < '1' || k[1]+dy > '8')continue;

        k[0] += dx;
        k[1] += dy;

        if(strcmp(k, s) == 0){
            if(s[0]+dx < 'A' || s[0]+dx > 'H' ||
                    s[1]+dy < '1' || s[1]+dy > '8'){
                k[0] -= dx;
                k[1] -= dy;
            }else{
                s[0] += dx;
                s[1] += dy;
            }
        }

    }

    printf("%s %s\n", k, s);

}
