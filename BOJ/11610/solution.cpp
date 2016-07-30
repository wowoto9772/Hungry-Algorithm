#include <stdio.h>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;


class ele{
public:
	ll p;
	int w;
	ele(){}
	ele(ll a, int b){
		p = a, w = b;
	}
};

vector <ele> q[2000003];

ll dp[2000003];

int main(){

	int n;
	scanf("%d", &n);


	while (n--){

		int t, p, w;
		scanf("%d %d %d", &t, &p, &w);

		q[t].emplace_back(p, w);

	}

	for (int i = 1; i <= 2000000; i++){
		dp[i] = max(dp[i], dp[i - 1]);
		for (int j = 0; j < q[i].size(); j++){
			int nxt = i + q[i][j].w;
			dp[nxt] = max(dp[nxt], dp[i] + q[i][j].p);
		}
	}

	printf("%lld\n", dp[2000000]);

}