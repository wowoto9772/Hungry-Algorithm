#include <cstdio>

#include <vector>

#include <algorithm>

using namespace std;

vector < vector < pair <int,int> > > lnk;
vector < int > hgt, add;
vector < vector <int> > lv;

#define a first
#define v second

void dfs(int h, int c){

    hgt[c] = h;
    lv[h].push_back(c);

    for(int i=0; i<lnk[c].size(); i++){

        pair <int,int> n = lnk[c][i];

        if(!hgt[n.a]){

            add[n.a] = n.v;
            dfs(h+1, n.a);

        }

    }

}

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n, d;
        scanf("%d %d", &n, &d);

        int hd = d;
        d <<= 1;

        add.clear();
        add.resize(n+1);
        hgt.clear();
        hgt.resize(n+1);
        lnk.clear();
        lnk.resize(n+1);
        lv.clear();
        lv.resize(n+1);

        for(int i=1; i<n; i++){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);

            z <<= 1;

            lnk[x].emplace_back(y, z);
            lnk[y].emplace_back(x, z);
        }

        dfs(1, 1);

        int ans = 0;

        vector < int > cst(n+1); // cst[x] : from x to ~ maximum length

        for(int i=n; i>=1; i--){

            for(const auto &e : lv[i]){

                int MV[] = {0, 0};

                for(const auto &f : lnk[e]){

                    if(hgt[e] < hgt[f.a]){

                        // my son

                        if(MV[0] < cst[f.a]){

                            MV[0] = cst[f.a];

                            sort(MV, MV+2);

                        }

                    }

                }

                if(MV[0] < hd){

                    // appropriate cut ~
                    int reduce = max(0, MV[0] + MV[1] - d);

                    ans += reduce;

                    cst[e] = MV[1] - reduce;

                }else{

                    for(const auto &f : lnk[e]){

                        if(hgt[e] < hgt[f.a]){

                            // my son

                            if(cst[f.a] >= hd){

                                ans += cst[f.a] - hd;

                            }

                        }

                    }

                    cst[e] = hd;

                }

                // MV[0] + MV[1] <= d

                cst[e] += add[e];

            }

        }

        printf("%d.%d\n", ans>>1, ((ans&1) ? 5 : 0));

    }

}
