#include <stdio.h>

#include <vector>

#include <set>

#include <algorithm>


using namespace std;

class ele{
public:

	int p, v, i;

	ele(){}
	ele(int _p, int _v, int _i){
		p = _p, v = _v, i = _i;
	}

	bool operator<(const ele &A)const{
		if(p == A.p)return v > A.v;
		return p < A.p;
	}

};

int main(){

	int n;
	scanf("%d", &n);

	vector < ele > v(n<<1);

	for(int i=0; i<n; i++){

		int x, y;
		scanf("%d %d", &x, &y);
		v[(i<<1)] = {x, 1, i+1};
		v[(i<<1)|1] = {y, -1, i+1};
	}

	sort(v.begin(), v.end());

	int ans = 0, x;
	int tmp = 0;

	for(int i=0; i<(n<<1); i++){
		tmp += v[i].v;
		if(ans < tmp){
			ans = tmp;
			x = i;
		}
	}

	printf("%d\n", ans);

	set <int> p;

	for(int i=0; i<=x; i++){
		if(v[i].v == 1)p.insert(v[i].i);
		else{
			p.erase(v[i].i);
		}
	}

	for(auto &e : p){
		printf("%d ", e);
	}

}
