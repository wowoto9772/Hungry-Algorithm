#include <stdio.h>

int mp['T'+3]['T'+3];

char str[1000003];

int main(){

	mp['A']['A'] = 'A', mp['A']['G'] = 'C', mp['A']['C'] = 'A', mp['A']['T'] = 'G';
	mp['G']['A'] = 'C', mp['G']['G'] = 'G', mp['G']['C'] = 'T', mp['G']['T'] = 'A';
	mp['C']['A'] = 'A', mp['C']['G'] = 'T', mp['C']['C'] = 'C', mp['C']['T'] = 'G';
	mp['T']['A'] = 'G', mp['T']['G'] = 'A', mp['T']['C'] = 'G', mp['T']['T'] = 'T';

	int n;
	scanf("%d", &n);

	scanf("%s", str);

	for(int i=n-2; i>=0; i--){
		str[i] = mp[str[i]][str[i+1]];
		str[i+1] = 0;
	}

	printf("%s\n", str);

}
