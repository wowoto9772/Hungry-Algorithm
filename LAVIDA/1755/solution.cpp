//#include <stdio.h>
//#include <algorithm>
//
//#define ll long long
//
//using namespace std;
//
//class S{
//public:
//	int x, y;
//	ll l;
//	ll x_[2], y_[2];
//	double m;
//	bool inf;
//	bool operator<(const S &A)const{
//		if (x == A.x){
//			if (y == A.y){
//				if (l == A.l){
//					if (m == A.m)return inf > A.inf;
//					return m < A.m;
//				}
//				return l < A.l;
//			}
//			return y < A.y;
//		}
//		return x < A.x;
//	}
//}R[1125003];
//
//class P{
//public:
//	ll x, y;
//	bool operator<(const P &A)const{
//		if (x == A.x)return y < A.y;
//		return x < A.x;
//	}
//}N[1503];
//
//int GCD(int a, int b){
//	int r = 1;
//	while (r){
//		r = a % b;
//		a = b;
//		b = r;
//	}return r;
//}
//
//ll SQ(ll x[], ll y[], ll x2[], ll y2[]){
//	ll ret = (x[0] - x2[1]) * (x[0] - x2[1]);
//	ret += (y[0] - y2[1]) * (y[0] - y2[1]);
//	ret = sqrt(ret);
//	ll ret2 = (x[0] - x2[0]) * (x[0] - x2[0]);
//	ret2 += (y[0] - y2[0]) * (y[0] - y2[0]);
//	ret2 = sqrt(ret2);
//	ret *= ret2;
//	return sqrt(ret);
//}
//
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n;
//		scanf("%d", &n);
//
//		for (int i = 0; i < n; i++)scanf("%lld %lld", &N[i].x, &N[i].y);
//		
//		sort(N, N + n);
//
//		int top = 0;
//
//		for (int i = 0; i < n-1; i++){
//			for (int j = i + 1; j < n; j++){
//				R[top].x = (N[i].x + N[j].x);
//				R[top].y = (N[i].y + N[j].y);
//				R[top].l = (N[i].x - N[j].x) * (N[i].x - N[j].x);
//				R[top].l += (N[i].y - N[j].y) * (N[i].y - N[j].y);
//				R[top].x_[0] = N[i].x, R[top].x_[1] = N[j].x;
//				R[top].y_[0] = N[i].y, R[top].y_[1] = N[j].y;
//				R[top].inf = false;
//				if (N[i].x == N[j].x)R[top].m = 0;
//				else if (N[i].y == N[j].y)R[top].m = 0, R[top].inf = true;
//				else{
//					int a = N[i].x - N[j].x;
//					int b = N[i].y - N[j].y;
//					R[top].m = (double)b / a;
//				}
//				top++;
//			}
//		}
//
//		sort(R, R + top);
//
//		ll ans = 0;
//
//		for (int i = 0; i < top - 1; i++){
//			if (R[i].x != R[i + 1].x)continue;
//			if (R[i].y != R[i + 1].y)continue;
//			if (R[i].l != R[i + 1].l)continue;
//			int l = i, r = top - 1, m;
//			while (l <= r){
//				m = (l + r) / 2;
//				
//				if(R[m].x > R[i].x){
//					r = m - 1;
//				}
//				else if (R[m].x < R[i].x){
//					l = m + 1;
//				}
//				else{
//					if (R[m].y > R[i].y){
//						r = m - 1;
//					}
//					else if (R[m].y < R[i].y){
//						l = m + 1;
//					}
//					else{
//						if (R[m].l <= R[i].l){
//							l = m + 1;
//						}
//						else
//							r = m - 1;
//					}
//				}
//			}
//			if (R[m].x != R[i].x || R[m].y != R[i].y || R[m].l != R[i].l)m--;
//			
//			l = i + 1, r = m;
//
//			while (l <= r){
//				m = (l + r) / 2;
//				for (int j = i + 1; j <= m; j++){
//					ll k = SQ(R[i].x_, R[i].y_, R[j].x_, R[j].y_);
//					ans = ans < k ? k : ans;
//				}
//			}
//		}
//
//		printf("%lld\n", ans);
//	}
//}

#include <stdio.h>
#include <algorithm>

#define ll long long

using namespace std;

class S{
public:
	int x, y;
	ll l;
	bool operator<(const S &A)const{
		if (l == A.l){
			if (x == A.x)return y < A.y;
			return x < A.x;
		}
		return l < A.l;
	}

	ll rx[2], ry[2];
}R[1125003];

class P{
public:
	ll x, y;
	bool operator<(const P &A)const{
		if (x == A.x)return y < A.y;
		return x < A.x;
	}
}N[1503];

ll SQ(ll x[], ll y[], ll x2[], ll y2[]){
	ll ret = (x[0] - x2[1]) * (x[0] - x2[1]);
	ret += (y[0] - y2[1]) * (y[0] - y2[1]);
//	ret = sqrt(ret);
	ll ret2 = (x[0] - x2[0]) * (x[0] - x2[0]);
	ret2 += (y[0] - y2[0]) * (y[0] - y2[0]);
//	ret2 = sqrt(ret2);
	ret *= ret2;
	return sqrt(ret);
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)scanf("%lld %lld", &N[i].x, &N[i].y);

		sort(N, N + n);

		int top = 0;

		for (int i = 0; i < n - 1; i++){
			for (int j = i + 1; j < n; j++){
				R[top].x = (N[i].x + N[j].x);
				R[top].y = (N[i].y + N[j].y);
				R[top].l = (N[i].x - N[j].x) * (N[i].x - N[j].x);
				R[top].l += (N[i].y - N[j].y) * (N[i].y - N[j].y);
				R[top].rx[0] = N[i].x, R[top].rx[1] = N[j].x;
				R[top].ry[0] = N[i].y, R[top].ry[1] = N[j].y;
				top++;
			}
		}

		sort(R, R + top);

		ll ans = 0;

		for (int i = 0; i < top - 1; i++){
			int l = i + 1, r = top - 1, m;
			while (l <= r){
				m = (l + r) / 2;

				if (R[m].l < R[i].l)l = m + 1;
				else if (R[m].l > R[i].l)r = m - 1;
				else{
					if (R[m].x < R[i].x){
						l = m + 1;
					}
					else if (R[m].x > R[i].x){
						r = m - 1;
					}
					else{
						if (R[m].y < R[i].y){
							l = m + 1;
						}
						else if (R[m].y > R[i].y){
							r = m - 1;
						}
						else{
							break;
						}
					}
				}
			}

			for (int j = m; j < top; j++){
				if (R[i].l == R[j].l && R[i].x == R[j].x && R[i].y == R[j].y){
					long long tmp = SQ(R[i].rx, R[i].ry, R[j].rx, R[j].ry);
					if (ans < tmp)ans = tmp;
				}
				else{
					break;
				}
			}

		}

		printf("%lld\n", ans);
	}
}

/*
	x, y, x2, y2
	x+x2 / y+y2
	(x2-x)^2 + (y2-y)^2
	*/