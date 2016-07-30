#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

char str[1000003];

int main(){
	while (!strcmp(str, ""))gets(str);
	int s = strlen(str);

	string wrd = "";

	int c = 0;
	for (int i = 0; i<s; i++){
		if (str[i] == ' '){
			if (wrd != "")c++;
			wrd = "";
		}
		else{
			wrd += str[i];
		}
	}

	if (wrd != "")c++;

	printf("%d\n", c);
}