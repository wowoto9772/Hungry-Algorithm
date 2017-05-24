#include <cstdio>

using namespace std;
using ll = long long;

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n;
		scanf("%d", &n);
		
		ll c[2] = {};
		for(ll i=2; i<=n; i<<=1){
			c[0] += n/i;
		}
		for(ll i=5; i<=n; i*=5){
			c[1] += n/i;
		}
		if(c[0] > c[1])c[0] = c[1];
		printf("%d\n", c[0]);
	}
	
}