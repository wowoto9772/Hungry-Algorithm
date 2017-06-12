#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char str[23];

int main(){
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector < pair <int,int> > work;
    
    for(int i=1; i<=n; i++){
        scanf("%s", str);
        if(strcmp(str, "order") == 0){
            int t, o;
            scanf("%d %d", &t, &o);
            work.emplace_back(o, t);
        }else if(strcmp(str, "sort") == 0){
            sort(work.begin(), work.end());
        }else{
            int v;
            scanf("%d", &v);
            for(int j=0; j<work.size(); j++){
                if(work[j].second == v){
                    work.erase(work.begin()+j);
                    break;
                }
            }
        }
        if(work.empty())printf("sleep");
        else{
            for(auto &e : work)printf("%d ", e.second);
        }
        printf("\n");
    }

}