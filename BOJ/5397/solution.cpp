#include <cstdio>
#include <cstring>

using namespace std;

int p[2];
char stk[2][1000003];

char pop(int id){
    return (p[id] > 0) ? stk[id][--p[id]] : 0;
}

void push(int id, char ch){
    stk[id][p[id]++] = ch;
}

char str[1000003];

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        scanf("%s", str);
        int s = strlen(str);

        p[0] = p[1] = 0;

        char c;

        for(int i=0; i<s; i++){
            if(str[i] == '-'){
                pop(0);
            }else if(str[i] == '<'){
                c = pop(0);
                if(c)push(1, c);
            }else if(str[i] == '>'){
                c = pop(1);
                if(c)push(0, c);
            }else{
                push(0, str[i]);
            }
        }
        while(c = pop(0)){
            push(1, c);
        }
        while(c = pop(1)){
            printf("%c", c);
        }
        printf("\n");
        
    }

}
