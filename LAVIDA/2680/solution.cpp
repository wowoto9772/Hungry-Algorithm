#include <stdio.h>
#include <queue>

using namespace std;

class ele{
public:
	int v, t;
	ele(){}
	ele(int a, int b){ v = a, t = b; }
	bool operator<(const ele &A)const{
		return v < A.v;
	}
};

int main(){
	int n, t;
	scanf("%d %d", &n, &t);

	int cur = 0;
	priority_queue <ele> q;
	for (int i = 1; i <= n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if (cur < b)cur = b;
		q.push(ele(a, b));
	}

	int ans = 0;
	bool chk[49] = { 0 };
	while (!q.empty()){
		ele pop = q.top();
		q.pop();

		if (chk[pop.t]){
			for (int i = pop.t; i >= 0; i--){
				if (chk[i])continue;
				chk[i] = true;
				ans += pop.v;
				break;
			}
		}
		else{
			chk[pop.t] = true;
			ans += pop.v;
		}
	}

	printf("%d\n", ans);
}