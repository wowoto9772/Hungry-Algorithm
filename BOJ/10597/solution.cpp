#include <cstdio>
#include <cstring>

using namespace std;

char str[103];

bool chk[53];
int a[53], s, limit, top;

bool ended;

void dfs(int c){

    if(s == c){
        ended = true;
        for(int i=0; i<top; i++)printf("%d ", a[i]);
        return ;
    }

    int v = 0;

    for(int i=c; i<s && !ended; i++){
        v = v * 10 + str[i] - '0';
        if(v <= limit){
            if(chk[v])continue;
            chk[v] = true;
            a[top++] = v;
            dfs(i+1);
            top--;
            chk[v] = false;
        }else{
            break;
        }
    }

}

int main(){

    scanf("%s", str);

    s = strlen(str);
    int c = s;

    for(int i=1;!limit;i++){
        if(i < 10){
            c--;
        }else
            c -= 2;
        if(c == 0){
            limit = i;
        }
    }

    dfs(0);

}
