#include <stdio.h>

#include <functional>

#include <vector>
#include <queue>

#include <algorithm>

using namespace std;

class ele {
	public:
		int s, e;
		bool operator<(const ele &A)const {
			if (s == A.s)return e < A.e;
			return s < A.s;
		}
}I[300003];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++){
		scanf("%d %d", &I[i].s, &I[i].e);
		I[i].e += I[i].s;
	}

	sort(I, I + n);

	priority_queue <int, vector <int>, greater <int> > work;

	int cur = -1;
	int maxi = n;
	int mini = 0;

	for (int i = 0; i < n; i++) {

		if (cur < I[i].s)cur = I[i].s;

		while (!work.empty()) {
			if (work.top() + m < cur) {
				work.pop();
			}
			else {
				break;
			}
		}

		if (work.empty()) {
			mini++;
			work.push(I[i].e);
		}else{
			if(work.top() <= cur){
				work.pop();
				work.push(I[i].e);
			}else{
				mini++;
				work.push(I[i].e);
			}
		}

	}

	printf("%d", maxi - mini);

}
