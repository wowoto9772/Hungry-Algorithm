#include <stdio.h>
#include <algorithm>

using namespace std;

class ele{
public:
	int t, id;
	bool operator<(const ele &A)const{
		return t < A.t;
	}
}I[100003];

int U[100003];

int main(){

	int t;
	scanf("%d", &t);

	while (t--){
		int n, L, k;
		scanf("%d %d %d", &n, &L, &k);

		for (int i = 0; i < n; i++){
			int p;
			scanf("%d %d", &p, &I[i].id);

			U[i] = I[i].id;

			int d = abs(I[i].id) / I[i].id;

			if (d == 1){
				I[i].t = L - p;
			}
			else{
				I[i].t = p;
			}
		}

		sort(I, I + n);

		int l = 0, r = n - 1;

		int ans = 0;
		for (int i = 0; i < k; i++){
			if (I[i].t == I[i + 1].t){
				if (I[i].id < 0 && I[i + 1].id > 0){
					if (U[l] > U[r]){
						ele tmp = I[i];
						I[i] = I[i + 1];
						I[i + 1] = tmp;
					}
				}
				else if (I[i].id > 0 && I[i + 1].id < 0){
					if (U[l] < U[r]){
						ele tmp = I[i];
						I[i] = I[i + 1];
						I[i + 1] = tmp;
					}
				}
			}

			if (I[i].id > 0)ans = U[r--];
			else
				ans = U[l++];
		}

		printf("%d\n", ans);
	}

}