#include <stdio.h>
#include <algorithm>

using namespace std;

int stk[2003];

void swp(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int main(){
	int L1, L2, n;
	scanf("%d %d %d", &L1, &L2, &n);

	if (L1 > L2){
		swp(&L1, &L2);
	}

	for (int i = 0; i < n; i++){
		scanf("%d", &stk[i]);
	}

	sort(stk, stk + n);

	int ans = 0;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j)continue;
			int cmp = L1 - stk[i];
			if (cmp < stk[i])continue;
			int cmp2 = L2 - stk[j];
			if (cmp2 < stk[j])continue;

			int l = i + 1, r = n - 1, m;
			while (l <= r){
				m = (l + r) / 2;
				if (stk[m] > cmp)r = m - 1;
				else
					l = m + 1;
			}

			int m1 = m;
			if (stk[m1] > cmp)m1--;

			if (i < m1){

				l = j + 1, r = n - 1;
				while (l <= r){
					m = (l + r) / 2;
					if (stk[m] > cmp2)r = m - 1;
					else
						l = m + 1;
				}

				int m2 = m;
				if (stk[m2] > cmp2)m2--;

				if (j < m2){
					for (int x = m1; x >= m1 - 3 && x > i; x--){
						if (x == j || x == i)continue;
						for (int y = m2; y >= m2 - 3 && y > j; y--){
							if (y == x || y == i || y == j)continue;
							int tmp = stk[i] + stk[j] + stk[x] + stk[y];
							if (ans < tmp)ans = tmp;
						}
					}
				}
			}
		}
	}

	if (!ans)printf("Impossible\n");
	else{
		printf("%d\n", ans);
	}
}