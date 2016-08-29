#include <stdio.h>
#include <algorithm>

using namespace std;

int gcd(int a, int b){

	int m = 1;

	while(m){
		m = a % b;
		a = b;
		b = m;
	}

	return a;

}

vector < pair<int,int> > v;

int x[203], y[203];

int main(){

	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		scanf("%d %d", &x[i], &y[i]);
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i == j)continue;
			int dx = x[j] - x[i];
			int dy = y[j] - y[i];

			if(dy == 0)v.emplace_back(1, 0);
			else if(dx == 0)v.emplace_back(0, 1);
			else{
				if(dx < 0)dx *= -1, dy *= -1;

				int g = gcd(abs(dx), abs(dy));

				dx /= g, dy /= g;

				v.emplace_back(dx, dy);

			}

		}

	}

	sort(v.begin(), v.end());

	int ans = 0;

	for(int i=0; i<v.size(); i++){
		int j = i;
		while(j < v.size() && v[i].first == v[j].first && v[i].second == v[j].second)j++;
		if(i+1 <= j){
			ans++;
		}
		i = j;
	}

	printf("%d\n", ans);

}
