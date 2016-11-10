#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i, begin, end) for(__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i+=1-2*((begin) > (end)))

using namespace std;

char s[200003];

int main(){

    scanf("%s", s);
    int n = strlen(s);

    int i, ans = 0, l = 0;

    rep(i,0,n){
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y'){
            ans = max(ans, l);
            l = 0;
        }   else{
        l++;
        }
    }

    ans = max(ans, l);

    printf("%d\n", ans+1);

}
