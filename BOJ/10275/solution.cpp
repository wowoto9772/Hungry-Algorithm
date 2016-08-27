#include <stdio.h>
#include <functional>
#include <queue>
#include <algorithm>

#define ll long long

using namespace std;

int main(){

	int t;
	scanf("%d", &t);

	while(t--){

		ll v, a, b;
		scanf("%lld %lld %lld", &v, &a, &b);

		priority_queue < ll, vector < ll >, greater < ll > > q;

		v = a + b;
		q.push(v);

		int d = 0;

		while(!q.empty()){

			v = q.top(); q.pop();

			if(a < b)swap(a, b);

			if(a >= v){
				a -= v;
				v = 0;
			}

			if(b >= v){
				b -= v;
				v = 0;
			}

			if(v){
				d++;
				q.push(v>>1);
				q.push(v>>1);
			}

		}

		printf("%d\n", d);

	}

}
