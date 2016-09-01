#include <stdio.h>

#include <string.h>

#include <vector>

#include <string>

using namespace std;

bool isVowel(int a){
	if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')return true;
	return false;
}

bool hasNGNY(char *str){
	for(int i=0; i<6; i++){
		if(i+1 < 6 && str[i] == 'n' && (str[i+1] == 'g' || str[i+1] == 'y'))return true;
	}
	return false;
}

int getSylla(char *str){

	int s = strlen(str);

	if(s > 6)return 3;
	else if(s == 6){
		// 3 or 2
		if(hasNGNY(str))return 2;
		else
			return 3;
	}else if(s > 3){
		return 2;
	}else if(s < 3){
		return 1;
	}else if(s == 3){
		// 2 or 1
		if(isVowel(str[0]))return 2;
		else
			return 1;
	}

}

char _str[1000];
char str[1000];

int main(){

	int t;
	scanf("%d ", &t); // for buffer

	int tc = 0;

	while(t--){

		fgets(_str, sizeof(_str), stdin);

		int len = strlen(_str);

		// for '\n';
		if(_str[len-1] == '\n'){
			_str[len-1] = 0;
			len--;
		}

		// upper to lower
		for(int i=0; i<len; i++)if(_str[i] >= 'A' && _str[i] <= 'Z')_str[i] += 'a' - 'A';

		vector < string > _verse;

		for(char *str = strtok(_str, ",."); str != NULL; str = strtok(NULL, ",.")){
			_verse.push_back(string(str));
		}

		int A = 0, B = 0, C = 0, D = 0;

		int sylla[4] = {0};

		int ind = 0;

		for(int i=0; i<_verse.size() && i<4; i++){

			const char *__str = _verse[i].c_str();

			int ind = 0;

			len = strlen(__str);

			for(int j=0; j<len; j++){

				if(__str[j] != ' '){

					sscanf(__str+j, "%s", str);

					int s = strlen(str);

					// printf("[%s]\n", str);

					sylla[i] += getSylla(str);

					j += s-1;

				}
			}

			// printf("%d\n", sylla[i]);
		}


		// alternating pair : 1,3 and 2,4

		for(int i=0; i<4; i++){
			if(8 <= sylla[i] && sylla[i] <= 12)A += 10;
		}

		// maximum of 4 verses

		if(A > 40)A = 40;

		for(int i=0; i<2 && i+2 < _verse.size(); i++){

			// minimum length of word is 2
			if(_verse[i].substr(_verse[i].size()-2) == _verse[i+2].substr(_verse[i+2].size()-2))B += 20;

			if(sylla[i] == sylla[i+2])C += 10;

		}

		// penalty of 10 for each extra verse.
		if(_verse.size() > 4)D = (_verse.size() - 4) * 10;

		printf("Case #%d: %d %d %d %d %d\n", ++tc, A, B, C, D, A+B+C-D);

		//fgets(_str, sizeof(_str), stdin); // for buffer

	}

}
