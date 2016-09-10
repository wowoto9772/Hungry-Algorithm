#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int x, y;
	scanf("%d %d", &x, &y);

	int c = 0;

	vector <int> a = {x,x,x};

	while(true){
		sort(a.begin(), a.end());
		printf("%d %d %d\n", a[0], a[1], a[2]);
		if(a[2] == y){
			printf("%d", c);
			break;
		}else{
			int goal = a[1] - a[0] + 1;
			a[2] = max(goal, y);
			c++;
		}
	}

}
