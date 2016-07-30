#include <stdio.h>
#include <queue>
#include <algorithm>

#define ll long long

using namespace std;

ll P[10003];
bool p[100003];

int main(){

	int top = 0;
	int nx;

	queue <int> v, c;

	for (int i = 2; i*i <= 100000; i++){
		nx = i;
		if (p[i])continue;
		v.push(i);
		c.push(top);
		P[top++] = i;
		for (int j = i*i; j <= 100000; j += i)p[j] = true;
	}
	for (int i = nx + 1; i <= 100000; i++){
		if (!p[i]){
			v.push(i);
			c.push(top);
			P[top++] = i;
		}
	}

	vector <int> val;

	while (!v.empty()){
		int vl = v.front(); v.pop();
		int cl = c.front(); c.pop();
		for (int i = cl + 1; i < top; i++){
			ll g = vl * P[i];
			if (g > 100001)break;
			else{
				// v.push(g);
				val.push_back(g);
			}
		}
	}

	sort(val.begin(), val.end());

	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		int l = 0, r = val.size() - 1, m;

		while (l <= r){
			m = (l + r) / 2;
			if (val[m] < n)l = m + 1;
			else
				r = m - 1;
		}

		if (val[m] < n)m++;

		printf("%d\n", val[m]);
	}
}