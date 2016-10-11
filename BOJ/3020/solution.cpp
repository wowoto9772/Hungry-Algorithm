#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n, h;
    scanf("%d %d", &n, &h);

    vector <int> a;
    vector <int> b;

    for(int i=1; i<=n; i++){
        int e;
        scanf("%d", &e);
        if(i&1)a.push_back(e);
        else
            b.push_back(e);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int x = 200003, y = 1;

    for(int i=1; i<=h; i++){
        int p = lower_bound(a.begin(), a.end(), i) - a.begin();
        int q = upper_bound(b.begin(), b.end(), h-i) - b.begin();
        int r = (a.size()-p) + (b.size()-q);
        if(x > r)x = r, y = 1;
        else if(x == r)y++;

    }

    printf("%d %d\n", x, y);

}
