#include <stdio.h>

#include <string.h>

#include <string>

#include <map>

using namespace std;

char str[4];

int main(){

    int c = 0;

    map <string, int> b;

    while(scanf("%s", &str) == 1){
        c++;

        string it = string(str);

        b[it]++;

    }

    string a[] = {"Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex"};

    for(int i=0; i<7; i++){
        printf("%s %d %.2lf\n", a[i].c_str(), b[a[i]], (double)b[a[i]] / c);
    }

    printf("Total %d 1.00\n", c);

}
