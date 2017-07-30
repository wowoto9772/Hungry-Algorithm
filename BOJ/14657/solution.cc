#include <cstdio>
#include <vector>

using namespace std;

class ele{
    public:
        int a, c;
        ele(){}
        ele(int _a, int _c){
            a = _a, c = _c;
        }
};

class my{
    public:
        int x, y, z;
        my(){}
        my(int _x, int _y, int _z){
            x = _x, y = _y, z = _z;
        }
};

vector < vector <ele> > v;

my dfs(int c, int p){
    my ret = {0, 0, c};
    for(auto &e : v[c]){
        if(e.a == p)continue;
        my nxt = dfs(e.a, c);
        if(ret.x < nxt.x+1){
            ret.x = nxt.x+1;
            ret.y = nxt.y+e.c;
            ret.z = nxt.z; // find root
        }else if(ret.x == nxt.x+1 &&
                ret.y > nxt.y+e.c){
            ret.y = nxt.y+e.c;
            ret.z = nxt.z;
        }
    }
    return ret;
}

int main(){

    int n, t;
    scanf("%d %d", &n, &t);

    v.resize(n+1);

    for(int i=1; i<=n-1; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].emplace_back(b, c);
        v[b].emplace_back(a, c);
    }

    int ans = dfs(dfs(1, 0).z, 0).y;

    printf("%d\n", ans/t + ((ans%t) > 0 ? 1 : 0));

}
