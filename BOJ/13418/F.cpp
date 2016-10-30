#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int p[1003];

int findParent(int parent){
    if(p[parent] == parent)return parent;
    return p[parent] = findParent(p[parent]);
}

class ele{
    public:
        int a, b, c;
        bool operator<(const ele &A)const{
            return c < A.c;
        }
};

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    vector <ele> edge(m+1);

    int ans1 = 0, ans2 = 0;

    for(int i=0; i<m+1; i++){
        scanf("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].c);
        if(edge[i].c)edge[i].c = 0;
        else
            edge[i].c = 1;
    }

    sort(edge.begin(), edge.end());

    for(int i=0; i<=n; i++)p[i] = i;
    for(auto &e : edge){
        int a = e.a, b = e.b, c = e.c;
        if(findParent(a) == findParent(b))continue;
        p[findParent(a)] = findParent(b);
        ans1 += c;
    }

    sort(edge.begin(), edge.end());
    for(int i=0; i<=n; i++)p[i] = i;

    for(int i=edge.size()-1; i>=0; i--){
        ele e = edge[i];
        int a = e.a, b = e.b, c = e.c;
        if(findParent(a) == findParent(b))continue;
        p[findParent(a)] = findParent(b);
        ans2 += c;
    }

    printf("%d\n", ans2*ans2-ans1*ans1);

}
