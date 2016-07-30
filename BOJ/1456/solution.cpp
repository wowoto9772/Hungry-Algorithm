#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

bool p[10000003];

vector <ll> S;

int fndV(ll a) {

	int l = 0, r = S.size() - 1, m;

	while (l <= r) {
		m = (l + r) / 2;
		if (S[m] <= a)l = m + 1;
		else
			r = m - 1;
	}

	if (S[m] > a)m--;

	return m;

}

int main() {

	ll a, b;
	scanf("%lld %lld", &a, &b);

	int lim = sqrt(b);

	vector <ll> P;

	for (ll i = 2; i*i <= b; i++) {
		if (!p[i]) {
			P.push_back(i);
			for (ll j = i + i; j <= lim; j += i) {
				p[j] = true;
			}
		}
	}

	int s = P.size();
	for (int i = 0; i < s; i++) {
		ll x = P[i];

		while(true){
			if (b / P[i] < x)break;
			x *= P[i];
			S.push_back(x);
		}
	}


	S.push_back(0);
	sort(S.begin(), S.end());

	printf("%d\n", fndV(b) - fndV(a - 1));

}

//
//#include <stdio.h>
//#include <math.h>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//#define ll long long
//
//bool p[10000003];
//
//vector <ll> S;
//
//int fndV(int a) {
//
//	int l = 0, r = S.size() - 1, m;
//
//	while (l <= r) {
//		m = (l + r) / 2;
//		if (S[m] <= a)l = m + 1;
//		else
//			r = m - 1;
//	}
//
//	if (S[m] > a)m--;
//
//	return m;
//
//}
//
//int main() {
//
//	ll a, b;
//	scanf("%lld %lld", &a, &b);
//
//	ll lim = sqrt(b);
//
//	vector <ll> P;
//
//	for (ll i = 2; i*i <= b; i++) {
//		if (!p[i]) {
//			P.push_back(i);
//			for (int j = i + i; j <= lim; j += i) {
//				p[j] = true;
//			}
//		}
//	}
//
//	int s = P.size();
//	for (int i = 0; i < s; i++) {
//		ll x = P[i];
//		for (int k = 1;; k++) {
//			x *= P[i];
//			if (x > b)break;
//			S.push_back(x);
//		}
//	}
//
//	S.push_back(0);
//	sort(S.begin(), S.end());
//
//	printf("%d\n", fndV(b) - fndV(a - 1));
//
//}