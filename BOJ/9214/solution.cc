#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

string str;

string prev(string s){
	string ret;
	int top = 0;
	int a = s.size();
	for(int i=0; i<a; i+=2){
		int c = s[i] - '0';
		for(int j=1; j<=c; j++)ret += s[i+1];
	}
	return ret;
}

char _str[203];

int main(){
	
	int tc = 0;
	
	while(scanf("%s", _str) == 1){
		if(strcmp(_str, "0") == 0)break;
		str = string(_str);
		string tmp;
		while((str.size() & 1) == 0){
			tmp = prev(str);
			if(tmp != str)str = tmp;
			else
				break;
		}
		printf("Test %d: ", ++tc);
		printf("%s\n", str.c_str());
	}
	
}