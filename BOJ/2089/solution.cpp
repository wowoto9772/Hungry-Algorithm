#include <stdio.h>
#include <vector>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	if (!n)printf("0\n");
	else {

		vector <int> v;

		while (n) {

			v.push_back(n % 2 ? 1 : 0);

			if (n < 0) {

				n = -n;
				n++;
				n /= 2;

			}
			else {

				n /= -2;

			}

		}

		for (int i = v.size() - 1; i >= 0; i--)printf("%d", v[i]);

		printf("\n");

	}

}