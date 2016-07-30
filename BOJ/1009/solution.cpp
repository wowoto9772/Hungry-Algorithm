#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	vector <int> n[10];

	for (int i = 1; i <= 9; i++){
		bool chk[10] = { 0 };
		int x = i;
		while (!chk[x]){
			chk[x] = true;
			n[i].push_back(x);
			x *= i;
			x %= 10;
		}
	}
	n[0].push_back(10);

	int t;
	scanf("%d", &t);

	while (t--){
		int a, b;
		scanf("%d %d", &a, &b);
		a %= 10;
		int g = b % n[a].size();
		g--;
		if (g == -1)g = n[a].size() - 1;
		printf("%d\n", n[a][g]);
	}
}