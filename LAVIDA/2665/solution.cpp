#include <stdio.h>
#include <string.h>

char str[15];
long long gcd(long long a, long long b){
	long long mod = 1;
	while (mod){
		mod = a % b;
		a = b;
		b = mod;
	}return a;
}

int main(){
	while (scanf("%s", str) == 1){
		if (!strcmp(str, "END"))break;

		int s = strlen(str);
		bool par = false;

		long long z = 0; // integer, fraction
		long long mz = 0; // minus
		long long p = 0;

		int c = 0, d = 0;
		for (int i = 0; i < s; i++){
			if (str[i] == '(')par = true;
			else if (str[i] == '.'){
				for (int j = i + 1; j < s; j++){
					if (str[j] == '('){
						par = true;
						for (int k = j + 1; k < s; k++){
							if (str[k] == ')')break;
							d++;
						}
						break;
					}
					else{
						c++;
					}
				}
				for (int j = 1; j <= d; j++)p = p * 10 + 9;
				if (d == 0)p = 1;
				for (int j = 1; j <= c; j++)p = p * 10;

				mz = z;
				bool mend = false;
				for (int j = i + 1; j < s; j++){
					if (str[j] == '('){
						mend = true;
					}
					else if (str[j] == ')'){
						break;
					}
					else{
						if (!mend)mz = mz * 10 + str[j] - '0';
						z = z * 10 + str[j] - '0';
					}
				}

				if (mz != z){
					z -= mz;
				}
				break;
			}
			else{
				z = z * 10 + str[i] - '0';
			}
		}

		if (p == 0)p = 1;
		long long g = gcd(z, p);
		z /= g;
		p /= g;
		printf("%lld/%lld\n", z, p);
	}
}