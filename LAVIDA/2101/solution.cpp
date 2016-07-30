/*
	3
	200 250 300
	2 200

	250±îÁö Çï±â 200¿ø
	200/300±îÁö ÃÑ 50*2 + 50*2 = 400
*/


//#include <stdio.h>
//#include <limits.h>
//#include <memory.h>
//
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//long long m(long long a, long long b){ return a < b ? a : b; }
//
//int main()
//{
//	int n, a;
//	scanf("%d", &n);
//
//	vector <int> I;
//
//	for (int i = 1; i <= n; i++){
//		scanf("%d", &a);
//		I.push_back(a);
//	}
//
//	I.push_back(0);
//	sort(I.begin(), I.end());
//
//	int S = I.size();
//
//	long long T, H;
//
//	scanf("%lld %lld", &T, &H);
//
//	long long dp[3003][2] = { { 0, 0 }, { I[1] * T, H } };
//	long long X[3003] = { 0, I[1]};
//	for (int i = 2; i < S; i++)X[i] = X[i - 1] + I[i];
//
//	for (int i = 2; i < S; i++){
//		if (!dp[i][0])dp[i][0] = LLONG_MAX;
//		if (!dp[i][1])dp[i][1] = LLONG_MAX;
//		dp[i][0] = m(dp[i][0], m(dp[i - 1][0], dp[i - 1][1]) + T * I[i]);
//		for (int j = 1; j <= i; j++){
//			if(j<i)dp[i][0] = m(dp[i][0], dp[j][1] + (X[i] - X[j] - (i - j) * I[j]) * T); // j : hel ==> infl
//			dp[i][1] = m(dp[i][1], m(dp[j - 1][0], dp[j - 1][1]) + H + ((i - (j - 1))*I[i] - (X[i] - X[j - 1])) * T); // i : hel in (j to i)
//		}
//	}
//
//	printf("%lld\n", m(dp[S - 1][0], dp[S - 1][1]));
//}

#include <stdio.h>
#include <limits.h>
#include <memory.h>

#include <vector>
#include <algorithm>

using namespace std;

long long m(long long a, long long b){ return a < b ? a : b; }

int main()
{
	int n, a;
	scanf("%d", &n);

	vector <int> I;

	for (int i = 1; i <= n; i++){
		scanf("%d", &a);
		I.push_back(a);
	}

	I.push_back(0);
	sort(I.begin(), I.end());

	int S = I.size();

	long long T, H;

	scanf("%lld %lld", &T, &H);

	long long dp[3010][2] = { { 0, 0 }, { I[1] * T, H } };
	long long X[3010] = { 0, I[1] };
	for (int i = 2; i < S; i++)X[i] = X[i - 1] + I[i];

	for (int i = 2; i < S; i++){
		if (!dp[i][0])dp[i][0] = LLONG_MAX;
		if (!dp[i][1])dp[i][1] = LLONG_MAX;
		dp[i][0] = m(dp[i][0], m(dp[i - 1][0], dp[i - 1][1]) + T * I[i]);
		for (int j = 1; j <= i; j++){ // i-th hel
			dp[i][1] = m(dp[i][1], m(dp[j - 1][0], dp[j - 1][1]) + H + ((i - (j - 1))*I[i] - (X[i] - X[j - 1])) * T); // i : hel in (j to i)
		}
		for (int j = i + 1; j < S; j++){ // i-th hel
			if (!dp[j][0])dp[j][0] = LLONG_MAX;
			dp[j][0] = m(dp[j][0], dp[i][1] + (X[j] - X[i] - (j - i)*I[i]) * T);
		}
	}

	printf("%lld\n", m(dp[S - 1][0], dp[S - 1][1]));
}