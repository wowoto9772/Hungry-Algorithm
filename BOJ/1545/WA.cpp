#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

char str[53], out[53];

bool isPalindrome(int l, int r){
    if(l >= r)return true;
    if(str[l] == str[r])return isPalindrome(l+1, r-1);
    return false;
}

int main(){

    scanf("%s", str);

    int s = strlen(str);

    sort(str, str+s);

    if(!isPalindrome(0, s-1))strcpy(out, str);

    for(int i=0; i<s; i++){
        for(int j=i+1; j<s; j++){
            swap(str[i], str[j]);
            if(!isPalindrome(0, s-1)){
                if(strcmp(out, "") == 0 || strcmp(out, str) > 0)strcpy(out, str);
            }
            swap(str[i], str[j]);
        }
    }

    if(strcmp(out, "") == 0)out[0] = '-', out[1] = '1';

    printf("%s\n", out);


}
