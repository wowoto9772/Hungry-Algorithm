#include <stdio.h>
#include <map>

using namespace std;

char a[13];
char b[13];
char c[13];

int main(){

	map <string, long long> val, mul;
	val["black"] = 0;
	mul["black"] = 1;
	val["brown"] = 1;
	mul["brown"] = 10;
	val["red"] = 2;
	mul["red"] = 100;
	val["orange"] = 3;
	mul["orange"] = 1000;
	val["yellow"] = 4;
	mul["yellow"] = 10000;
	val["green"] = 5;
	mul["green"] = 100000;
	val["blue"] = 6;
	mul["blue"] = 1000000;
	val["violet"] = 7;
	mul["violet"] = 10000000;
	val["grey"] = 8;
	mul["grey"] = 100000000;
	val["white"] = 9;
	mul["white"] = 1000000000;

	scanf("%s %s %s", a, b, c);
	printf("%lld\n", (val[(string)a] * 10LL + val[(string)b]) * mul[(string)c]);
}