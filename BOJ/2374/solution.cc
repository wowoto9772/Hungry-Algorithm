#include <stdio.h>
#include <set>
#include <queue>
#include <algorithm>
#define ll long long

using namespace std;

class ele{
	public:
		int l, r, v;

		ele(){}
		ele(int _l, int _r, int _v){
			l = _l, r = _r, v = _v;
		}

		bool operator<(const ele &A)const{
			if(v == A.v)return l > A.l;
			return v > A.v;
		}
};

int main(){

	int n;
	scanf("%d", &n);

	priority_queue < ele > q;
	set <int> v;

	for(int i=1; i<=n; i++){
		int x;
		scanf("%d", &x);
		q.emplace(i, i, x);
		v.insert(x);
	}

	ll ans = 0;

	while(!q.empty() && q.size() > 1){
		ele w = q.top();q.pop();
		while(!q.empty()){
			if(w.v == q.top().v){
				if(w.r + 1 == q.top().l){
					w.r = q.top().r;
					q.pop();
				}else{
					break;
				}
			}else{
				break;
			}
		}

		if(q.empty())break;
		else{
			int goal = *v.lower_bound(w.v+1);
			ans += goal - w.v;
			w.v = goal;
			q.emplace(w);
		}
	}

	printf("%lld\n", ans);

}
