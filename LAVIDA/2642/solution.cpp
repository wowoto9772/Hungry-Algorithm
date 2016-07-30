#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	int A, B;
	scanf("%d %d", &A, &B);

	vector <int> a, m;
	for (int i = 2; i*i <= A && A != 1; i++){
		if (A%i)continue;
		else{
			a.push_back(i);
			int c = 0;
			while (!(A%i)){
				A /= i;
				c++;
			}
			m.push_back(c * B);
		}
	}

	if (A != 1){
		a.push_back(A);
		m.push_back(B);
	}

	int ans = a.size();
	vector <int> cur;
	for (int i = 0; i < a.size(); i++)cur.push_back(1);

	while (true){
		bool flag = false;
		for (int i = 0; i < a.size(); i++){
			if (cur[i] < m[i])flag = true;
		}
		if (!flag){
			break;
		}
		else{
			for (int i = 0; i < a.size(); i++){
				cur[i] += cur[i];
			}
			ans++;
		}
	}

	printf("%d\n", ans);
}