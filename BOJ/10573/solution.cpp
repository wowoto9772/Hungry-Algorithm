#include <stdio.h>
#include <string.h>

#define ll long long

char str[83];

ll dp[83][13];

int s;

bool pos(){
	for (int i = 0; i < s - 1; i++){
		if (str[i] > str[i + 1])return false;
	}
	return true;
}

int main(){

	int t;
	scanf("%d", &t);

	while (t--){

		scanf("%s", str);

		s = strlen(str);

		ll ans = 0;
		if (pos()){

			// dp[i][j] : i-th number (j), count
			for (int i = s - 1; i >= 0; i--){
				for (int j = 1; j <= 9; j++){
					if (i == s - 1)dp[i][j] = 1;
					else{
						dp[i][j] = 0;
						for (int k = j; k <= 9; k++){
							dp[i][j] += dp[i + 1][k];
						}
					}
				}

				dp[i][0] = 0;
				for (int k = 1; k <= 9; k++){
					dp[i][0] += dp[i][k];
				}
			}

			for (int i = 0; i < s; i++){
				int m = 0;
				if (i == 0)m = 1;
				else
					m = str[i - 1] - '0';

				ll k = (str[i] - '0') - 1;
				for (int j = m; j <= k; j++){
					ans += dp[i][j];
				}

				if (i)ans += dp[i][0];
			}

			ans++; // include zero
		}
		else{
			ans = -1; // impossible
		}

		printf("%lld\n", ans);

	}

}