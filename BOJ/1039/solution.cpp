#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

bool chk[1000003][13];

int value(string a){

    int s = a.size();
    int v = 0;

    for(int i=0; i<s; i++){
        v = v * 10 + a[i] - '0';
    }

    return v;

}

string pars(int v){

    string ret;

    while(v){
        ret += (char)(v % 10 + '0');
        v /= 10;
    }

    reverse(ret.begin(), ret.end());

    return ret;

}

int main(){

    int s, k;
    scanf("%d %d", &s, &k);

    queue < pair<int,int> > q;

    chk[s][0] = true;
    q.emplace(s, 0);

    int ans = -1;

    while(!q.empty()){

        pair <int,int> f = q.front(); q.pop();

        if(f.second == k)ans = max(ans, f.first);
        else{

            string a = pars(f.first);

            int l = a.size();
            int m = f.second + 1;

            for(int i=0; i<l; i++){
                for(int j=i+1; j<l; j++){

                    swap(a[i], a[j]);

                    if(a[0] != '0'){
                        int p = value(a);
                        if(chk[p][m]){
                            swap(a[i], a[j]);
                            continue;
                        }
                        chk[p][m] = true;
                        q.emplace(p, m);
                    }

                    swap(a[i], a[j]);

                }
            }

        }

    }

    printf("%d\n", ans);

}
