#include <cstdio>

using namespace std;

int main(){
	
	int n;
	scanf("%d", &n);
	
	int cur = 0;
	
	for(int i=0; i<n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(cur % (a+b) < b){
			cur += (b - cur%(a+b));
		}
		cur++;
	}
	
	printf("%d\n", cur);
	
	
}