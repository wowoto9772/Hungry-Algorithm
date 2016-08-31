#include <stdio.h>

#include <algorithm>

using namespace std;

pair <int,int> p[50003];

int main(){

	int t, n;
	scanf("%d %d", &t, &n);

	for(int i=0; i<n; i++){
		scanf("%d", &p[i].second);
		p[i].first = abs(p[i].second);
	}

	sort(p, p+n);

	int ans = 0;

	int d = 0, pre = 0;
	
	for(int i=0; i<n; i++){
		d += abs(p[i].second - pre);
		if(d > t)break;
		pre = p[i].second;
		ans++;
	}

	printf("%d\n", ans);

}
