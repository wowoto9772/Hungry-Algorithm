#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector <ll> a(n);

	for (int i = 0; i < n; i++)scanf("%lld", &a[i]);

	sort(a.begin(), a.end());

	int max = 1, c = 1;
	ll y = a[0], x = a[0];
	for (int i = 1; i < n; i++){
		if (x == a[i]){
			c++;
			if (max < c){
				max = c;
				y = a[i];
			}
		}
		else{
			c = 1;
			x = a[i];
		}
	}

	printf("%lld\n", y);
}