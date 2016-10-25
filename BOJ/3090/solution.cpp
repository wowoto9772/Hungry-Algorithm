#include <cstdio>
#include <vector>
#include <algorithm>
 
using ll = long long;
 
using namespace std;
 
int main(){
 
    int n, T;
    scanf("%d %d", &n, &T);
 
    vector <int> e(n);
 
    for (int i = 0; i < n; i++){
        scanf("%d", &e[i]);
    }
 
    vector <int> ans;
 
    int l = 0, r = 1000000000, m;
 
    while (l <= r){
 
        m = (l + r) / 2;
        vector <int> t = e;
 
        ll cst = 0;
 
        for (int i = 0; i < n-1; i++){
            int v = abs(t[i] - t[i + 1]);
            if (v > m){
                if (t[i] > t[i + 1]){
                    int g = (t[i + 1] + m);
                    cst += t[i] - g;
                    t[i] = g;
                }
                else{
                    int g = (t[i] + m);
                    cst += t[i + 1] - g;
                    t[i + 1] = g;
                }
            }
        }
 
        for (int i = n - 1; i >= 1; i--){
            int v = abs(t[i] - t[i - 1]);
            if (v > m){
                if (t[i] > t[i - 1]){
                    int g = (t[i - 1] + m);
                    cst += t[i] - g;
                    t[i] = g;
                }
                else{
                    int g = (t[i] + m);
                    cst += t[i - 1] - g;
                    t[i - 1] = g;
                }
            }
        }
 
        if (cst <= T){
            ans = t;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
 
    }
 
    for (int i = 0; i < ans.size(); i++)printf("%d ", ans[i]);
 
}