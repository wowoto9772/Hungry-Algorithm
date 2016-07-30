#include <stdio.h>
#include <vector>

using namespace std;

int n, e[15];

void Lotto(int limit, vector<int> ans) {

	if (limit == n) {
		if (ans.size() == 6) {
			for (int i = 0; i < 6; i++)printf("%d ", ans[i]);
			printf("\n");
		}
		return;
	}

	ans.push_back(e[limit]);
	Lotto(limit + 1, ans);

	ans.pop_back();
	Lotto(limit + 1, ans);

}
int main()
{
	while (scanf("%d", &n) == 1 && n) {

		for (int i = 0; i < n; i++)scanf("%d", &e[i]);
		
		vector <int> ans;

		Lotto(0, ans);

		printf("\n");
	}

}