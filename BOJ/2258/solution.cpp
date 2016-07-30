#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

class ele{
public:
	
	int w, v;

	bool operator<(const ele &A)const{
		if (v == A.v)return w > A.w;
		return v < A.v;
	}

}I[100003];

int s[100003];
int p[100003];

int main(){

	int n, g;
	scanf("%d %d", &n, &g);

	for (int i = 0; i < n; i++){
		scanf("%d %d", &I[i].w, &I[i].v);
	}

	sort(I, I + n);
	
	s[0] = I[0].w;
	p[0] = I[0].v;
	for (int i = 1; i < n; i++){
		s[i] = s[i - 1] + I[i].w;
		p[i] = p[i - 1] + I[i].v;
	}

	int ans = INT_MAX;
	int cur = 0;

	for (int i = 0; i < n; i++){

		int l = 0, r = i - 1, m = -1;

		while (l <= r){
			m = (l + r) / 2;
			if (I[m].v < I[i].v)l = m + 1;
			else{
				r = m - 1;
			}
		}

		while (m >= 0 && I[m].v == I[i].v)m--;

		if (m == -1){
			if (I[i].w >= g)ans = min(ans, I[i].v);
			if (s[i] >= g)ans = min(ans, p[i]);
		}
		else{
			if (s[m] + I[i].w >= g)ans = min(ans, I[i].v);
			if (s[i] >= g){
				ans = min(ans, (i - m)*I[i].v);
			}
		}
	}

	if (s[n-1] < g)ans = -1;

	printf("%d\n", ans);
}