#include <cstdio>
#include <map>
#include <string>

using namespace std;

char str[1003];

int main(){
    
    int t;
    scanf("%d", &t);
    
    int tc = 0;
    
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        
        map <string, int> cnt;
        
        for(int i=1; i<=n; i++)scanf("%*s", str);
        
        while(m--){
            int e;
            scanf("%s %d %*s", str, &e);
            cnt[string(str)] += e;
        }
        
        int c = 0, x = 0;
        string out;
        for(auto &e : cnt){
            if(x < e.second){
                x = e.second, c = 1;
                out = e.first;
            }
            else if(x == e.second)c++;
        }
        
        printf("VOTE %d: ", ++tc);
        if(c == 1)printf("THE WINNER IS %s %d", out.c_str(), cnt[out]);
        else{
            printf("THERE IS A DILEMMA");
        }
        
        puts("");
        
    }

}