#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

#define ll long long

int main(){
	ll n;
	scanf("%lld", &n);

	vector <ll> X, Y;

	for (ll i = 2; i*i <= n && n != 1; i++){
		if (n%i)continue;
		X.push_back(i), Y.push_back(0);
		while (!(n%i)){
			n /= i;
			// distinct positive integers (Y1+1)(Y2+1)...(YK+1)
			Y[Y.size() - 1]++;
		}
	}

	if (n != 1){
		X.push_back(n);
		Y.push_back(1);
	}

	map <ll, bool> chk;
	ll cur = 1;
	int ans = 0;

	for (int i = 0; i < Y.size(); i++){
		int r = Y[i];
		for (int j = 1; j <= r; j++){
			cur *= X[i];
			if (chk[cur] == 0){
				chk[cur] = true;
				cur = 1;
				ans++;
			}
		}
	}

	printf("%d\n", ans);
}

/*
755366363136000
15(AC)

2 22
3 5
5 3
7 2
11 2

2
22
222
2222
22222
222222
23
3
33
35
5
57
7
11

[11]

giving the number of points obtained by the second player, 
assuming she plays as good as possible.

가능한한 k(maximum)
*/