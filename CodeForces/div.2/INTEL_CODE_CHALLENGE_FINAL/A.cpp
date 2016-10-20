#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

char a[10], b[10];

int main(){

    scanf("%s %s", a, b);

    string day[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

    int e = 0, f = 0;

    for(int i=0; i<7; i++){
        if(string(a) == day[i]){
            e = i;
        }
        if(string(b) == day[i]){
            f = i;
        }
    }

    int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int x = f - e;

    if(x < 0)x += 7;

    for(int i=0; i<11; i++){
        if(x == d[i] % 7){
            printf("YES\n");
            return 0;
        }
    }
    
    printf("NO\n");

    return 0;

}
