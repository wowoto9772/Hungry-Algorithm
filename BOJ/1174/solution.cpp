#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

vector <ll> sexy;

void dfs(int c, ll k) {

	if (k) {
		sexy.push_back(k);
	}

	for (ll j = c - 1; j >= 0; j--) {
		dfs(j, k * 10LL + j);
	}

}

int main() {

	dfs(10, 0LL);

	sexy.push_back(0);

	sort(sexy.begin(), sexy.end());

	int n;
	scanf("%d", &n);

	if (n > sexy.size())printf("-1\n");
	else
		printf("%lld\n", sexy[n - 1]);

}