#include <stdio.h>
#include <algorithm>

using namespace std;

#define max(a, b) (a < b ? b : a)
int dp[13299];

class ele{
public:
	int s, d, v;
	bool operator <(const ele &A)const{
		if (s == A.s){
			if (d == A.d)return v > A.v;
			return d < A.d;
		}
		return s < A.s;
	}
}I[100003];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		for (int i = 0; i <= 10080; i++)dp[i] = 0;

		for (int i = 0; i < n; i++){
			scanf("%d %d %d", &I[i].s, &I[i].d, &I[i].v);
		}

		sort(I, I + n);

		int s = 0;

		for (int i = 0; i <= 10080; i++){
			if (dp[i + 1] < dp[i])dp[i + 1] = dp[i];
			if (s < n){
				if (i == I[s].s){
					if (dp[i + I[s].d] < dp[i] + I[s].v){
						dp[i + I[s].d] = dp[i] + I[s].v;
					}
					s++;
					i--;
				}
			}
		}
		printf("%d\n", dp[10080]);
	}
}
