#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class ele{
	public:
		int s, t;
		ele(){}
		ele(int _s, int _t){
			s = _s, t = _t;
		}

		bool operator<(const ele &A)const{
			if (s == A.s)return t < A.t;
			return s < A.s;
		}
}e[200000];

int main(){

	int n;
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%d %d", &e[i].s, &e[i].t);
	}
	sort(e, e+n);

	priority_queue < int, vector<int>, greater<int> > q;
	int c = 0;

	for(int i=0; i<n; i++){
		while(!q.empty()){
			if (q.top() <= e[i].s)q.pop();
			else
				break;
		}
		if (q.size() == c){
			c++;
		}
		q.push(e[i].t);
	}

	printf("%d\n", c);

}
