#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int p[200003], c[200003];

int findParent(int u){
    if(c[u] || p[u] == u)return u;
    else{
        return p[u] = findParent(p[u]);
    }
}   

int main(){

    int n, q;
    scanf("%d %d", &n, &q);

    p[1] = 1;
    for(int i=2; i<=n; i++)scanf("%d", &p[i]);

    vector < vector <int> > _qry;

    q = n+q-1;
    for(int i=1; i<=q; i++){
        vector <int> e;
        int t;
        scanf("%d", &t);

        e.push_back(t);

        if(t == 1){
            int a, b;
            scanf("%d %d", &a, &b);
            e.push_back(a);
            e.push_back(b);
        }else{
            int a;
            scanf("%d", &a);
            e.push_back(a);
            c[a]++;
        }
        _qry.push_back(e);
    }

    vector < string > ans;

    for(int i=_qry.size()-1; i>=0; i--){
        vector <int> qry = _qry[i];
        if(qry.size() == 3){
            int a = qry[1], b = qry[2];
            if(findParent(a) == findParent(b))ans.push_back("YES");
            else{
                ans.push_back("NO");
            }
        }else{
            c[qry.back()]--;
        }
    }

    for(int i=ans.size()-1; i>=0; i--){
        printf("%s\n", ans[i].c_str());
    }

}
