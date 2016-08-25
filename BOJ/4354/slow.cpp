#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

char str[1000003];

int main(){

	while(scanf("%s", str) == 1){

		if(!strcmp(str, "."))break;

		int s = strlen(str);

		int ans = 1;

		string _str = string(str);

		for(int i=1; i <= (s>>1); i++){
			if(s%i)continue;
			string cmpr = _str.substr(0, i);
			bool flag = false;
			for(int k=i; k<s && !flag; k+=i){
				string _cmpr = _str.substr(k, i);
				if(cmpr.compare(_cmpr))flag = true;
			}
			if(!flag){
				ans = s / i;
				break;
			}
		}

		printf("%d\n", ans);

	}
	
}
