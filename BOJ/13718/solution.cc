#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

char str[503];
char spc[503][28];

int main(){

    int s, n, m, k;
    scanf("%d %d %d %d", &s, &n, &m, &k);

    k--;
    scanf("%s", str);

    for(int i=0; i<n; i++){
        scanf("%s", spc[i]);
        sort(spc[i], spc[i]+m);
    }

    vector <int> v;
    while(k){
        v.push_back(k%m);
        k /= m;
    }
    while(v.size() < n)v.push_back(0);

    reverse(v.begin(), v.end());

    int p = 0;
    for(int i=0; i<s; i++){
        if(str[i] == '#'){
            printf("%c", spc[p][v[p]]);
            p++;
        }
        else
            printf("%c", str[i]);
    }

}
