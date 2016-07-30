#include <stdio.h>
#include <vector>

using namespace std;

int main() {

	int d, k;
	scanf("%d %d", &d, &k);

	for (int i = k - 1; k >= 1; i--) {

		vector <int> v;
		v.push_back(k);
		v.push_back(i);

		bool flag = false;
		
		while (v.size() < d) {

			v.push_back(v[v.size() - 2] - v.back());

			if (v.back() < 1 || v[v.size()-2] <= v.back()) {
				flag = true;
				break;
			}      
			     
		}

		if (flag)continue;

		printf("%d\n", v.back());
		printf("%d\n", v[v.size() - 2]);

		break;

	}

}