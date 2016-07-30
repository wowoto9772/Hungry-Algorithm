/*
	ax + by = gcd(a, b) : Diophantine equation
	> always has solution(x, y are integers)

	solve by using Euclidean algorithm

	ex) 7x + 5y = 1

	7 = 1*5 + 2
	5 = 2*2 + 1
	2 = 2*(1) + 0 > (1) is gcd(5, 7)

	gcd(5, 7) = 1
	= 5 - 2*2
	= 5 - 2(7-1*5)
	= 7*(-2) + 5*3

	x = -2, y = 3

	then, another solution
	(-2 - 5, 3 + 7), (-2 + 5, 3 - 7), ...

	X = x + bt
	Y = y - at
	(t is integer)

	extgcd()'s return value : (x, y)
*/

/*
	K kids, X candies > tot = X*K (X : positive natural number)
	K*X + 1 = CY (always at least one kid looses one candy)
	CY - KX = 1
	must gcd(C, K) = 1
*/

#include <stdio.h>
#include <vector>

using namespace std;

pair<long long, long long> extended_gcd(long long a, long long b) {
	if (b == 0) return make_pair(1, 0);
	pair<long long, long long> t = extended_gcd(b, a % b);
	return make_pair(t.second, t.first - t.second * (a / b));
}

int gcd(int a, int b){
	int m = 1;
	while (m){
		m = a % b;
		a = b;
		b = m;
	}return a;
}

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int K, C;
		scanf("%d %d", &K, &C);
		
		// -Kx + Cy = 1
		// K(-x) + Cy = 1
		// Kx' + Cy = 1
		// x' = -x

		if (gcd(K, C) != 1)printf("IMPOSSIBLE\n");
		else{
			pair <int, int> sol = extended_gcd(K, C);

			while (sol.first >= 0 || sol.second <= 0){
				sol.first -= C;
				sol.second += K;
			}

			// x : -sol.first
			printf("%d\n", sol.second); 
		}
	}
}