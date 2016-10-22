#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[53];

int main(){

    scanf("%s", str);

    int s = strlen(str);

    int a[] = {1, 0, 0};

    for(int i=0; i<s; i++){
        if(str[i] == 'A')swap(a[0], a[1]);
        else if(str[i] == 'B')swap(a[1], a[2]);
        else
            swap(a[0], a[2]);
    }

    for(int i=0; i<3; i++){
        if(a[i])printf("%d\n", i+1);
    }

}
