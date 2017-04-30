#include <cstdio>
#include <cstring>

using namespace std;

char v[] = "AEIOUaeiou";

int vowel(char c){
	for(int i=0; i<10; i++){
		if(c == v[i])return 1;
	}return 0;
}

char str[300];

int main(){
	
	while(fgets(str, sizeof(str), stdin)){
		if(strcmp(str, "#\n") == 0 || strcmp(str, "#") == 0)break;
		int s = strlen(str);
		if(str[s-1] == '\n')s--;
		int c = 0;
		for(int i=0; i<s; i++){
			c += vowel(str[i]);
		}
		printf("%d\n", c);
	}
	
}