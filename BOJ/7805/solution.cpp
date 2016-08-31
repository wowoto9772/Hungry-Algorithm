#include <stdio.h>

#include <string.h>

#include <algorithm>

using namespace std;

char str[28];

int main(){

	while(scanf("%s", str) == 1){

		int s = strlen(str);

		int c = 0;

		for(int i=0; i<s; i++){

			int m = i;
			for(int j=i+1; j<s; j++){
				if(str[m] > str[j])m = j;
			}

			if(m == i)continue;
			else{
				c++;
				swap(str[m], str[i]);
			}
		}

		printf("%d\n", c);

	}

}

