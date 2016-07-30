#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);

	string a;
	cin >> a;

	n--;

	int up = 0;

	bool nei = false;

	while (n--){
		string b;
		cin >> b;

		if (a < b){
			if (!up){
				up = 1;
				a = b;
			}
			else if (up == 1)a = b;
			else{
				nei = true;
			}
		}
		else if (a > b){
			if (!up){
				up = -1;
				a = b;
			}
			else if (up == -1)a = b;
			else{
				nei = true;
			}
		}
	}

	if (nei || !up)printf("NEITHER\n");
	else if (up == 1)printf("INCREASING\n");
	else
		printf("DECREASING\n");

}