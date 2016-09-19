#include <stdio.h>

#include <string.h>

#include <vector>

#include <algorithm>

using namespace std;

string str[5];
char _str[4];

int main(){

    int n = 5;

    for(int i=0; i<n; i++){
        scanf(" %c %c", &_str[0], &_str[1]);
        str[i] = string(_str);
    }

    sort(str, str+n);

    vector < int > v;

    int c[10] = {0};

    for(int i=0; i<5; i++){
        str[i][1] -= '0';
        c[str[i][1]]++;
    }

    if(str[0][0] == str[4][0]){
        if(str[0][1]+4 == str[4][1]){
            // 1
            v.push_back(str[4][1] + 900);
        }else{
            // 4
            for(int i=9; i>=1; i--){
                if(c[i]){
                    v.push_back(i + 600);
                    break;
                }
            }
        }
    }

    for(int i=1; i<=5; i++){
        if(c[i] * c[i+1] * c[i+2] * c[i+3] * c[i+4]){
            // 5
            v.push_back(500+i+4);
        }
    }

    for(int i=1; i<=9; i++){
        if(c[i] == 4)v.push_back(800+i); // 2
        else if(c[i] == 3){
            v.push_back(400+i); // 6
            for(int j=1; j<=9; j++){
                if(c[j] == 2){
                    v.push_back(700+10*i+j); // 3
                }
            }
        }else if(c[i] == 2){
            v.push_back(200+i); // 8
            for(int j=i+1; j<=9; j++){
                if(c[j] == 2){
                    v.push_back(300 + j*10 + i); // 7
                }
            }
        }
    }

    if(v.empty()){
        // 9
        for(int i=9; i>=1; i--){
            if(c[i]){
                v.push_back(100+i);
                break;
            }
        }
    }

    sort(v.begin(), v.end());

    printf("%d\n", v.back());

}
