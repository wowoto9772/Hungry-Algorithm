#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1000003];
int dy(int c){
	int &ret = dp[c];
	if (ret != -1)return ret;
	ret = 987654321;
	bool flg = false;
	for (int i = 2; i*i <= c; i++){
		if (c%i)continue;
		flg = true;
		ret = min(ret, 1 + max(dy(i), dy(c / i)));
	}
	if (!flg)ret = 0; // isPrime
	return ret;
}

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)dp[i] = -1;
	printf("%d\n", dy(n));

}