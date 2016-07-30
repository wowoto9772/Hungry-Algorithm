//#include <stdio.h>
//#include <queue>
//#include <vector>
//#include <algorithm>
//
//#define ll long long 
//
//using namespace std;
//
//class ele{
//public:
//
//	int mV, flg;
//	int pay, cpay;
//
//	ele(){}
//	ele(int a, int b, int c, int d){ mV = a, flg = b, pay = c, cpay = d; }
//
//	bool operator<(const ele &A)const{
//		if (mV == A.mV)return flg < A.flg;
//		return mV > A.mV;
//	}
//
//};
//
//int main(){
//
//	int n, k;
//	ll m;
//	scanf("%d %d %lld", &n, &k, &m);
//
//	priority_queue <ele> q;
//	for (int i = 1; i <= n; i++){
//		int a, b;
//		scanf("%d %d", &a, &b);
//
//		if (a > b)q.emplace(b, 1, a, b);
//		else
//			q.emplace(a, 0, a, b);
//	}
//
//	int ans = 0;
//	while (!q.empty() && m){
//		ele f = q.top(); q.pop();
//		
//		if (f.mV > m)break;
//		else{
//			if (f.flg){
//				if (k){
//					m -= f.mV;
//					ans++;
//					k--;
//				}
//				else{
//					q.emplace(f.pay, 0, f.pay, f.cpay);
//				}
//			}
//			else{
//				m -= f.mV;
//				ans++;
//			}
//		}
//	}
//
//	printf("%d\n", ans);
//
//}

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long 

using namespace std;

class ele{

public:

	int v, ind;

	ele(){}
	ele(int a, int b){ v = a, ind = b; }

	bool operator<(const ele &A)const{
		return v  A.v;
	}

};

bool sold[50003];

int main(){

	int n, k;
	ll m;
	scanf("%d %d %lld", &n, &k, &m);

	priority_queue <ele> ch, ex;
	for (int i = 1; i <= n; i++){
		int a, b;
		scanf("%d %d", &a, &b);

		ex.emplace(a, i);
		ch.emplace(b, i);
	}

	int ans = 0;

	while (m && ans < n){

		while (!ex.empty()){
			if (sold[ex.top().ind])ex.pop();
			else
				break;
		}

		while (!ch.empty()){
			if (sold[ch.top().ind])ch.pop();
			else
				break;
		}

		if (k && ch.top().v < ex.top().v){ // wrong answer ¤Ð¤Ð
			if (ch.top().v > m)break;
			sold[ch.top().ind] = true;
			m -= ch.top().v;
			ans++;
			k--;
		}
		else{
			if (ex.top().v > m)break;
			sold[ex.top().ind] = true;
			m -= ex.top().v;
			ans++;
		}

	}

	printf("%d\n", ans);

}

/*
5 1 9
2 1
8 1
4 3
5 4
6 3
*/