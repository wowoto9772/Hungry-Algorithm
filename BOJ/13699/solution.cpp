#include <cstdio>
#include <iostream>

using namespace std;
using ll = unsigned long long;

ll t[50];

int main(){

    int n;
    cin >> n;

    t[0] = 1LL;

    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            t[i] += t[j] * t[i-1-j];
        }
    }

    cout << t[n] << endl;

}
