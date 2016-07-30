#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long

int a[5003], b[5003], c[5003], d[5003];

int main(){
	ll L, S, M, D, B;
	while (scanf("%lld %lld %lld %lld %lld", &L, &S, &M, &D, &B) == 5 && L && S && M && D && B){
		for (int i = 1; i <= S; i++)scanf("%d", &a[i]);
		for (int i = 1; i <= M; i++)scanf("%d", &b[i]);
		for (int i = 1; i <= D; i++)scanf("%d", &c[i]);
		for (int i = 1; i <= B; i++)scanf("%d", &d[i]);

		vector <int> X, Y;

		X.resize(S*M);
		Y.resize(D*B);

		int top = 0;
		for (int i = 1; i <= S; i++){
			for (int j = 1; j <= M; j++){
				X[top++] = a[i] + b[j];
			}
		}

		top = 0;
		for (int i = 1; i <= D; i++){
			for (int j = 1; j <= B; j++){
				Y[top++] = c[i] + d[j];
			}
		}

		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());

		ll ans = 0;
		if (X.size() > Y.size()){
			for (int i = 0; i < Y.size(); i++){
				if (Y[i] < L){
					int l = 0, r = X.size() - 1, m = -1;
					while (l <= r){
						m = (l + r) / 2;
						if (X[m] + Y[i] <= L)l = m + 1;
						else
							r = m - 1;
					}
					if (X[m] + Y[i] > L)m--;
					ans += m + 1;
				}
				else{
					break;
				}
			}
		}
		else{
			for (int i = 0; i < X.size(); i++){
				if (X[i] < L){
					int l = 0, r = Y.size() - 1, m = -1;
					while (l <= r){
						m = (l + r) / 2;
						if (X[i] + Y[m] <= L)l = m + 1;
						else
							r = m - 1;
					}
					if (X[i] + Y[m] > L)m--;
					ans += m + 1;
				}
				else{
					break;
				}
			}
		}

		printf("%lld\n", ans);
	}
}