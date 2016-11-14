#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

char a[123];

int main(){

    int n;
    while(scanf("%d", &n) == 1 && n){
        double ans = -1.0;
        vector <string> out;
        for(int i=1; i<=n; i++){
            double v;
            scanf("%s %lf", a, &v);
            if(ans < v){
                ans = v;
                out.clear();
                out.push_back(string(a));
            }else if(ans == v)out.push_back(string(a));
        }
        for(auto &e : out)printf("%s ", e.c_str());
        printf("\n");
    }

}
