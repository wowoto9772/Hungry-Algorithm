#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector < int > ans;

int n;
char str[13][50003];

int dfs(int r, int c){
    if(str[r][c] == 'X')return 0;
    else if(c == n)return 1;
    else{
        str[r][c] = 'X';
        if(dfs(min(10, r+1), c+1)){
            ans.push_back(c);
            return 1;
        }else if(dfs(max(1, r-1), c+1)){
            return 1;
        }
        else
            return 0;
    }
}

int main(){

    scanf("%d", &n);
    
    for(int i=1; i<=10; i++)scanf("%s", str[i]+1);

    dfs(10, 1);

    reverse(ans.begin(), ans.end());

    printf("%d\n", ans.size());
    for(auto &e : ans)printf("%d 1\n", e);

}
