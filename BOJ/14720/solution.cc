#include <cstdio>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);

	int d = 0, c = 0;

	for (int i = 0; i < n; i++){
		int e;
		scanf("%d", &e);
		if (e == d){
			c++, d++;
			d %= 3;
		}
	}
	printf("%d\n", c);

}