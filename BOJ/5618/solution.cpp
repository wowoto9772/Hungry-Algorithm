#include <stdio.h>
#include <math.h>

#include <vector>
#include <queue>

#include <algorithm>

using namespace std;

int gcd(int a, int b){
	int m = 1;
	while (m){
		m = a % b;
		a = b;
		b = m;
	}return a;
}

int main(){

	int n;
	scanf("%d", &n);

	int a;
	scanf("%d", &a);
	for (int i = 1; i < n; i++){
		int b;
		scanf("%d", &b);
		a = gcd(a, b);
	}

	vector <int> p, c;
	for (int i = 2; i*i <= a; i++){
		if (a%i)continue;
		p.push_back(i);
		c.push_back(1);
		a /= i;
		while (!(a%i)){
			a /= i;
			c.back()++;
		}
	}

	if (a != 1){
		p.push_back(a);
		c.push_back(1);
	}

	queue <int> v, x;
	v.push(1), x.push(0);

	vector <int> ans;

	while (!v.empty()){

		int V = v.front(); v.pop();
		int X = x.front(); x.pop();

		ans.push_back(V);

		for (int i = X; i < p.size(); i++){
			for (int j = 1; j <= c[i]; j++){
				int Y = V * pow(p[i], j);
				v.push(Y);
				x.push(i + 1);
			}
		}

	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)printf("%d\n", ans[i]);
	
}