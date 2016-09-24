#include <stdio.h>
#include <map>
#include <vector>

#include <algorithm>

using namespace std;

int e[103];

int main(){

    int n;
    scanf("%d", &n);

    vector <int> p, c;
    map <int, int> ex;

    int top = 0;

    for(int i=1; i<=n; i++){

        scanf("%d", &e[i]);

        int v = e[i];

        for(int j=2; j*j <= v; j++){

            if(v % j)continue;

            if(ex.find(j) == ex.end()){
                ex[j] = top++;

                p.push_back(j);
                c.push_back(0);
            }

            int s = ex[j];

            while(!(v%j)){
                v /= j;
                c[s]++;
            }

        }

        if(v != 1){
            if(ex.find(v) == ex.end()){
                ex[v] = top++;
                p.push_back(v);
                c.push_back(1);
            }else{
                c[ex[v]]++;
            }
        }

    }

    int ans = 1;

    // average

    for(int i=0; i<p.size(); i++){

        c[i] /= n;

        for(int j=1; j<=c[i]; j++)ans *= p[i];

    }

    printf("%d ", ans);

    int cnt = 0;

    for(int i=1; i<=n; i++){

        for(int j=0; j<p.size(); j++){

            int d = 0;

            if(e[i] >= p[j]){

                while(!(e[i] % p[j])){
                    e[i] /= p[j];
                    d++;
                }

            }

            cnt += max(c[j] - d, 0);

        }

    }

    printf("%d\n", cnt);

}
