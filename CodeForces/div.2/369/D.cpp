#include <stdio.h>
#include <string>

using namespace std;

int sexy[4];

int main(){

	for(int i=0; i<4; i++)scanf("%d", &sexy[i]);

	// 00 01 10 11

	string se;
	string xy;

	if(sexy[0]){
		se += '1';
		for(int j=1; j<=sexy[0]; j++)se += '1';
	}

	if(sexy[3]){
		xy += '0';
		for(int j=1; j<=sexy[3]; j++)xy += '0';
	}

}
