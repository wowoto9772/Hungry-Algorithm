#include <stdio.h>
#include <algorithm>

using namespace std;

char str[53];

int main(){

	int n;
	scanf("%d", &n);

	scanf("%s", str);

	int c = 1;
	int t = 0;

	for(int i=0; i<n;){
		if(str[i] == 'S')c++, i++;
		else if(str[i] == 'L'){
			t++;
			if(!(t&1))c++;
			i++;
		}
	}

	printf("%d\n", min(c, n));

}
