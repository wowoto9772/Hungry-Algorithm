#include <stdio.h>

#include <vector>
#include <algorithm>

using namespace std;

vector <int> R, C;

int main()
{
	int r, c;
	scanf("%d %d", &r, &c);

	int n;
	scanf("%d", &n);

	R.push_back(0), C.push_back(0);
	R.push_back(r), C.push_back(c);

	for (int i = 1; i <= n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if (!a){// cut 가로
			C.push_back(b);
		}
		else{// cut 세로
			R.push_back(b);
		}
	}

	sort(R.begin(), R.end());
	sort(C.begin(), C.end());

	int ans = 0;

	for (int i = 0; i < C.size()-1; i++){
		for (int j = 0; j < R.size()-1; j++){
			int k = (C[i + 1] - C[i]) * (R[j + 1] - R[j]);
			ans = ans < k ? k : ans;
		}
	}
	
	printf("%d\n", ans);
}