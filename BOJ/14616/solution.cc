#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

class Line{
    public:
    ll x, y;
    Line(){}
    Line(ll _x, ll _y){
        x = _x, y = _y;
        ll g = gcd(x, y);
        x /= g, y /= g;
    }
    bool operator<(const Line &your)const{
        return x*your.y < y*your.x;
    }
    private:
    ll gcd(ll a, ll b){
        ll m = 1;
        while(m){
            m = a % b;
            a = b;
            b = m;
        }return a;
    }
};

int main(){
    
    int n;
    scanf("%d", &n);
    
    vector < Line > my[2];
    
    for(int i=0; i<n; i++){        
        for(int j=0; j<2; j++){
            int x, y;
            scanf("%d %d", &x, &y);
            my[j].emplace_back(x, y);
        }
        if(my[1][i] < my[0][i])swap(my[1][i], my[0][i]);
    }
    
    int cnt;
    scanf("%d", &cnt);

    vector <Line> laser;
    for(int i=0; i<cnt; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        laser.emplace_back(x, y);
    }
    
    sort(laser.begin(), laser.end());
    
    int ans = n;
    
    for(int i=0; i<n; i++){
        int l = 0, r = cnt-1, m;
        while(l <= r){
            m = (l+r) / 2;
            if(my[1][i] < laser[m])r = m - 1;
            else if(laser[m] < my[0][i])l = m + 1;
            else{
                ans--;
                break;
            }
        }
    }
    
    printf("%d\n", ans);

}