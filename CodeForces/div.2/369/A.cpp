#include <stdio.h>
#include <string.h>

char a[1003][1003];

int main(){

	int n;
	scanf("%d", &n);

	bool seat = false;

	for(int i=1; i<=n; i++){
		scanf("%s", a[i]);

		if(a[i][0] == a[i][1] && a[i][0] == 'O'){
			if(!seat){
				a[i][0] = a[i][1] = '+';
				seat = true;
			}
		}
		if(a[i][3] == a[i][4] && a[i][3] == 'O'){
			if(!seat){
				a[i][3] = a[i][4] = '+';
				seat = true;
			}
		}
	}

	if(seat){
		printf("YES\n");
		for(int i=1; i<=n; i++){
			printf("%s\n", a[i]);
		}
	}
	else{
		printf("NO\n");
	}

}
