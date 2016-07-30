#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

class ele{
public:
	string str;
	bool operator<(const ele &A)const{
		if (str.size() == A.str.size())return str < A.str;
		else
			return str.size() < A.str.size();
	}
}I[50003];

char str[53];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 0; i<n; i++){
		scanf("%s", str);
		I[i].str = (string)str;
	}

	sort(I, I + n);

	for (int i = 0; i < n; i++){
		if (i){
			if (I[i].str == I[i - 1].str)continue;
		}
		printf("%s\n", I[i].str.c_str());
	}
}