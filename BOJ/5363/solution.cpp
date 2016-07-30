#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

char str[203];

int main() {

	int n;
	scanf("%d", &n);

	fgets(str, 200, stdin); // for buffer

	while(n--){

		fgets(str, 200, stdin);

		int s = strlen(str);
		str[s - 1] = 0; // for '\n'

		string fi, se;

		int spc = 0;

		for (int i = 0; i < s; i++) {

			if (str[i] == ' ') {
				spc++;
				if (spc == 2) {
					printf("%s %s %s", str+i+1, fi.c_str(), se.c_str());
					printf("\n");
					break;
				}
			}
			else {
				if (spc == 0)fi += str[i];
				else if (spc == 1)se += str[i];
			}

		}

	}

}