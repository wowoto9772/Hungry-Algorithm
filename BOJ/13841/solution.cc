#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair <int,int> nxt[2003][2003];

int str_len(char *a){
    int r = 0;
    while(a[r] != 0)r++;
    return r;
}

int dp[2003][2003];
char str[2003];
int Max(int a, int b){
    if(a < b)a = b;
    return a;
}

int dy(int i, int j){
    if(i > j)return 0;
    else if(i == j)return 1;
        
    int &ret = dp[i][j];
    if(ret != -1)return ret;
    ret = 0;
    if(str[i] == str[j]){
        nxt[i][j] = {i+1, j-1};
        ret = 2 + dy(i+1, j-1);
    }
    if(ret < dy(i+1, j)){
        nxt[i][j] = {i+1, j};
        ret = dy(i+1, j);
    } 
    if(ret < dy(i, j-1)){
        nxt[i][j] = {i, j-1};
        ret = dy(i, j-1);
    }
    return ret;
}

int main(){
        
    while(scanf("%s", str) == 1){
        int s = str_len(str);
        for(int i=0; i<s; i++)for(int j=i; j<s; j++)dp[i][j] = -1;
        dy(0, s-1);
        int l = 0, r = s-1;
        string p = "";
        bool o = false;
        while(l <= r){
            if(str[l] == str[r]){
                p += str[l];
                if(l == r){
                    o = true;
                    break;
                }
            }
            auto &e = nxt[l][r];
            l = e.first, r = e.second;
        }
        string q = "";
        if(o){
            for(int j=p.size()-2; j>=0; j--){
                q += p[j];
            }
        }else{
            q = p;
            reverse(q.begin(), q.end());
        }
        p += q;
        printf("%s\n", p.c_str());
    }

}