#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int sum, gap;
		scanf("%d %d", &sum, &gap);
		if (sum < gap)printf("impossible\n");
		else{
			int a = (sum - gap) / 2;
			int b = sum - a;
			
			if (max(a, b) + min(a, b) == sum && max(a, b) - min(a, b) == gap){
				printf("%d %d\n", max(a, b), min(a, b));
			}
			else{
				printf("impossible\n");
			}
		}
	}
}