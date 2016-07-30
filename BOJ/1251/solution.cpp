#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

char str[53];

int main(){
	scanf("%s", str);

	int s = strlen(str);

	string ans = "";

	string l;
	for (int i = 0; i < s; i++){
		l = str[i] + l;
		for (int j = i + 1; j < s - 1; j++){
			string m, r;
			for (int k = j; k > i; k--){
				m += str[k];
			}
			for (int k = s - 1; k > j; k--){
				r += str[k];
			}
			if (ans == "")ans = l + m + r;
			else{
				if (ans > l + m + r){
					ans = l + m + r;
				}
			}
		}
	}

	printf("%s\n", ans.c_str());
}