//#include <stdio.h>
//#include <string.h>
//#include <map>
//using namespace std;
//
//long long a[30];
//char str[1000005];
//
//int main()
//{
//	freopen("large_dat11.in", "r", stdin);
//	freopen("large_dat11.out", "w", stdout);
//
//	for (int i = 0; i < 26; i++)scanf("%lld", &a[i]);
//
//	scanf("%s", str);
//
//	int s = strlen(str);
//	long long ans = 0;
//	long long g = 0;
//
//	map <long long, int> dp[26];
//
//	for (int i = 0; i < s; i++)
//	{
//		int x = str[i] - 'a'; // what is str[i]
//		ans += dp[x][g]; // now x character, g is sum of value
//
//		g += a[x];
//		dp[x][g]++;
//		// that start and end with the same letter 
//		// sum of values of all letters (assigned by A), 
//		// except for the first and the last one is equal to zero.
//	}
//
//	printf("%lld\n", ans);
//	return 0;
//}
//
///*
//// dp[x][g] �� 1�̸�, �ű���� ����
//// dp[x][g]�� 0�� �ƴ϶��, ������ dp[x][g] ���� ���� dp[x'][g] ��,
//// ���� 0�� ���� ����
//*/