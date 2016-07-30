#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int p[100003];
int s[300003];
int l[100003], r[100003];

vector <int> x;

int find(int v){
	int l = 0, r = x.size() - 1, m;
	while (l <= r){
		m = (l + r) / 2;
		if (x[m] < v)l = m + 1;
		else if (x[m] > v)r = m - 1;
		else
			return m;
	}
}

int main(){
	int n, q;
	scanf("%d %d", &n, &q);


	x.push_back(0);

	for (int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
		x.push_back(p[i]);
	}
	sort(p + 1, p + 1 + n);

	for (int i = 1; i <= q; i++){
		scanf("%d %d", &l[i], &r[i]);
		x.push_back(l[i]);
		x.push_back(r[i]);
	}

	sort(x.begin(), x.end());
	x.resize(distance(x.begin(), unique(x.begin(), x.end())));

	int top = 1;
	for (int i = 1; i < x.size(); i++){
		s[i] = s[i - 1];
		if (top <= n && x[i] == p[top]){
			s[i]++;
			top++;
		}
	}

	for (int i = 1; i <= q; i++){
		int a = find(l[i]), b = find(r[i]);
		if (a > b){
			int t = a;
			a = b;
			b = t;
		}
		printf("%d\n", s[b] - s[a - 1]);
	}
}