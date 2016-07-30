#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int a[1003], b[1003];
int c[1003], d[1003];

int main(){

	int t;
	scanf("%d", &t);

	while (t--){

		int S, m;
		scanf("%d %d", &S, &m);

		for (int i = 1; i <= m; i++)scanf("%d", &a[i]);
		for (int i = 1; i <= m; i++)scanf("%d", &b[i]);
		for (int i = 1; i <= m; i++)scanf("%d", &c[i]);
		for (int i = 1; i <= m; i++)scanf("%d", &d[i]);

		vector <int> x(m*m);
		int top = 0;

		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= m; j++){
				x[top++] = c[i] + d[j];
			}
		}

		sort(x.begin(), x.end());

		int ans = -40000003;

		for (int i = 1; i <= m && ans != S; i++){
			for (int j = 1; j <= m && ans != S; j++){
				int l = 0, r = top - 1, m;

				while (l <= r){
					m = (l + r) / 2;

					int cmp = S - (a[i] + b[j]);

					if (x[m] < cmp)l = m + 1;
					else if (x[m] > cmp)r = m - 1;
					else
						break;
				}

				int l_ = m - 2, r_ = m + 2;
				if (l_ < 0)l_ = 0;
				if (r_ >= top)r_ = top - 1;

				for (int k = l_; k <= r_; k++){
					int cmp = a[i] + b[j] + x[k];
					if (abs(S - ans) > abs(S - cmp)){
						ans = cmp;
					}
					else if (abs(S - ans) == abs(S - cmp)){
						if (ans > cmp)ans = cmp;
					}
				}
			}
		}

		printf("%d\n", ans);
	}
}