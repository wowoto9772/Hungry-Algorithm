#include <stdio.h>

#include <vector>

#include <algorithm>

using namespace std;

int main(){

	int x, y;
	scanf("%d %d", &x, &y);

	vector <int> a = {y,y,y};

	int c = 0;

	while(true){

		if(a[0] == x)break;

		a[0] = min(a[1]+a[2]-1, x);
		sort(a.begin(), a.end());

		c++;

	}

	printf("%d\n", c);

}
