#include <stdio.h>
#include <vector>

using namespace std;

class BIT{
public:
	vector <int> T;
	int S;
	BIT(const int n){
		S = n;
		T.resize(S + 1);
	}
	void Update(int p, int v){
		while (p <= S){
			T[p] += v;
			p += p & (-p);
		}
	}
	long long Sum(int p){
		long long ret = 0;
		while (p > 0){
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}
};

int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a < b ? b : a; }

int main()
{
	int n;
	scanf("%d", &n);
	
	BIT sx(n+1), sy(n+1);

	int d = 0;
	for (int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);

		sx.Update(i, 1);
		sy.Update(x, 1);

		int a = sx.Sum(i-1); // small X
		int b = i - sy.Sum(x-1); // big Y

		d = max(d, (a + b) - i);
	}

	printf("%d\n", n-d);
}
/*
3
2 1 3

*/

//#include <stdio.h>
//
//int dp[100003];
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	int d = 1;
//	scanf("%d", &dp[1]);
//	for (int i = 2; i <= n; i++){
//		int a;
//		scanf("%d", &a);
//		
//		int l = 1, r = d, m;
//		while (l <= r){
//			m = (l + r) / 2;
//			if (dp[m] > a)r = m - 1;
//			else
//				l = m + 1;
//		}
//
//		if (m == d){
//			if (dp[m] < a){
//				dp[++m] = a;
//				d++;
//			}
//			else if(dp[m] > a){
//				dp[m] = a;
//			}
//		}
//		else{
//			if(dp[m] > a)dp[m] = a;
//			else if(dp[m] < a){
//				dp[m + 1] = a;
//			}
//		}
//	}
//
//	printf("%d\n", n-d);
//}