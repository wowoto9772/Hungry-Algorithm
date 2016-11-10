#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int e[503];

int main(){

    int n;
    scanf("%d", &n);

    vector <int> v(n);

    vector < pair<int,int> > cmd;

    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    int k;
    scanf("%d", &k);

    for(int i=1; i<=k; i++){
        scanf("%d", &e[i]);
    }

    for(int i=1; i<=k; i++){
        vector <int> a = v;
        int c = 0, p = 0;
        for(int j=0; j<a.size(); j++){
            if(c+a[j] > e[i]){
                printf("NO\n");
                return 0;
            }else{
                c += a[j];
                if(c == e[i]){
                    p = j;
                    break;
                }
            }
        }
        if(c < e[i]){
            printf("NO\n");
            return 0;
        }else{
            for(int q=0; q<p; q++){
                int m = -1, x;
                for(int j=0; j<=p-q; j++){
                    if(m < a[j]){
                        bool pos = false;
                        if(j){
                            if(a[j-1] < a[j]){
                                pos = true;
                            }
                        }
                        if(j < a.size()-1){
                            if(a[j] > a[j+1]){
                                pos = true;
                            }
                        }
                        if(pos)m = a[j], x = j;
                    }
                }
                if(m == -1){
                    printf("NO\n");
                    return 0;
                }
                if(x && a[x-1] < a[x]){
                    cmd.emplace_back(i+x, 'L');
                    a[x-1] += a[x];
                    a.erase(a.begin()+x);
                    continue;
                }
                if(x < a.size()-1 && a[x] > a[x+1]){
                    cmd.emplace_back(i+x, 'R');
                    a[x] += a[x+1];
                    a.erase(a.begin()+x+1);
                }
            }
            a.erase(a.begin());
            v = a;
        }
    }

    if(!v.empty() || cmd.size() != n-k){
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for(auto &w : cmd){
        printf("%d %c\n", w.first, w.second);
    }

}
