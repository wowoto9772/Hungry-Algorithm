#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string str, out;
string one_dig[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
string two_dig[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
string two_dig2[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
string ths[] = { "", "thousand", "million", "billion" };

string func(int n, int d){
	string ret;
	if (n == 0)return "and zero";
	if (n >= 100){
		ret = one_dig[n / 100];
		ret += " hundred ";
	}
	if (n % 100){
		if (n >= 100 || !d)ret += " and ";
	}
	/*
	The word ¡®and¡¯ must appear between the least of the billions, millions or thousands groups and the units group
	if the units group is less than one hundred except when the units group equals 0
	e.g. compare ¡®two thousand and forty-six¡¯ with ¡®two thousand five hundred and fifty-seven¡¯.
	*/

	/*
	The word ¡®and¡¯ must appear after the word ¡®hundred¡¯ in all cases
	except when the value being converted is a round hundred
	e.g. compare ¡®one hundred thousand¡¯ with ¡®one hundred and twenty-three thousand¡¯.
	*/

	if (n % 100 >= 10 && n % 100 < 20){
		ret += two_dig[n % 100 - 10];
	}
	else if (n % 100 >= 20){
		ret += two_dig2[(n % 100) / 10 - 2];
		if (n % 10){
			ret += "-";
			ret += one_dig[(n % 10)];
		}
	}
	else{
		if (n % 10)ret += one_dig[n % 10];
	}


	return ret + " " + ths[d];
}

int main(){
	cin >> str;
	if (str[0] == '-')out = "in debit";
	else if (str == "$0" || str == "$0.0" || str == "$0." || str == "$0.00"){
		out = "";
	}
	else{
		out = "in credit";
	}

	int s = str.size();
	long long c = 0;
	long long k = 1;
	bool fraction = false;
	for (int i = s - 1; i >= 0; i--){
		if (str[i] == '$')break;
		else if (str[i] == '.'){
			if (c == 1)out = func(c, 0) + " cent " + out;
			else{
				out = func(c, 0) + " cents " + out;
			}
			c = 0;
			k = 1;
			fraction = true;
			continue;
		}
		else{
			c += (str[i] - '0') * k;
			k *= 10;
		}
	}

	if (!fraction)out = "and zero cents " + out;

	if (c == 1){
		out = "one dollar " + out;
	}
	else if (c == 0){
		out = "zero dollars " + out;
	}
	else if (c){
		int d = 0;
		out = "dollars " + out;
		while (c){
			int k = c % 1000;
			if (k)out = func(k, d) + " " + out;
			c /= 1000;
			d++;
		}
	}

	while (out[0] == ' ')out = out.substr(1);
	if (out.substr(0, 3) == "and")out = out.substr(4);
	s = out.size();
	for (int i = 0; i < s; i++){
		if (out[i] == out[i + 1] && out[i] == ' '){
			out = out.substr(0, i) + out.substr(i + 1);
			i--;
			s--;
		}
	}

	while (out[out.size() - 1] == ' ')out = out.substr(0, out.size() - 1);

	cout << out << endl;
}

/*
$100000040099.00
one hundred billion forty thousand and ninety-nine dollars and zero cents in credit
*/