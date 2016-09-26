#include <cstdio>

#include <string.h>

using namespace std;

char str[1000003];

int main(){

    int n;
    scanf("%d", &n);

    scanf("%s", str);

    int c = 0;

    for(int i=0; i<n; i++){
        if(str[i] == 'B'){
            c++;
            int l = i;
            for(int j=i+1; j<n; j++){
                if(str[j] == 'A'){
                    break;
                }
                l = j;
            }
            i = l;
        }
    }

    printf("%d\n", c);

}
