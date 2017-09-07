#include <cstdio>
#include <algorithm>

using namespace std;

char str[53][53];

int whatIs(char a){
    if(a <= 'z' && a >= 'a')return 0;
    else if(a <= '9' && a >= '0')return 1;
    else if(a == '#' || a == '*' || a == '&')return 2;
}

int dp[53][8];
int r, c;

int dy(int x, int s){
    if(x == r){
        if(s == 7)return 0;
        else{
            return 987654321;
        }
    }else{
        int &ret = dp[x][s];
        if(ret != -1)return ret;
        ret = 987654321;

        for(int i=0; i<c; i++){
            int v = whatIs(str[x][i]);
            if(s&(1<<v))continue;
            ret = min(ret, dy(x+1, s|(1<<v)) + min(i, c-i));
        }
        ret = min(ret, dy(x+1, s));
        return ret;
    }
}

int main(){
    
    scanf("%d %d", &r, &c);
    
    for(int i=0; i<r; i++){
        scanf("%s", str[i]);
    }
    
    for(int i=0; i<r; i++){
        for(int j=0; j<8; j++){
            dp[i][j] = -1;
        }
    }
    
    printf("%d\n", dy(0,0));

}