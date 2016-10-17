#include <cstdio>
#include <queue>

using namespace std;

struct ele {
    int r, c, d;
    ele() {}
    ele(int _r, int _c, int _d) {
        r = _r, c = _c, d = _d;
    }

    bool operator == (const ele &A)const{
        return r == A.r && c == A.c && d == A.d;
    }
};

char str[103][103];
int chk[103][103][2];

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < r; i++)scanf("%s", str[i]);

    queue < ele > q;

    vector < pair<int,int> > s, e;

    for (int i = 0; i < n; i++) {3
        for (int j = 0; j < n; j++) {
            if(str[i][j] == 'B') {
                s.emplace_back(i, j);
            }else if(str[i][j] == 'E'){
                e.emplace_back(i, j);
            }
        }
    }

    if(s.size() > 1){

        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        // 0 : parellel, 1 : vertical
        ele src = {s[0].first, s[0].second, s[0].second != s[1].second};
        ele snk = {e[0].first, e[0].second, e[0].second != e[1].second};

        for(int i=0; i<n; i++)for(int j=0; j<n; j++)chk[i][j][0] = chk[i][j][1] = -1;

        chk[src.r][src.c][src.d] = 0;
        q.emplace(src);

        while (!q.empty()) {

            ele f = q.front(); q.pop();

            int p = chk[f.r][f.c][f.d];

            if (f == snk) {
                printf("%d\n", p);
                return 0;
            }else{

                int c = p + 1;

                for (int i = 0; i < 4; i++) {

                    ele g = { f.r + dr[i], f.c + dc[i], f.d };
                    if (g.r < 0 || g.r >= r || g.c < 0 || g.c >= c)continue;
                    if (chk[g.r][g.c][g.d] != -1)continue;

                    if(g.d == 0

                    chk[g.r][g.c] = true;
                    q.emplace(g);

                }

            }

        }

        printf("%d\n", ans);

    }

}

