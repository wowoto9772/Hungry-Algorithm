#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[200003];

int main(){

    int s;
    scanf("%d", &s);
    scanf("%s", str);

    int c = 0;

    for(int i=0; i<s; i++){
        if(str[i] == '<')c++;
        else
            break;
    }

    for(int i=s-1; i>=0; i--){
        if(str[i] == '>')c++;
        else
            break;
    }

    printf("%d\n", c);

}
