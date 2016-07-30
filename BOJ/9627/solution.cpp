#include <stdio.h>
#include <string.h>

#include <string>
#include <vector>

using namespace std;

string num[1003] = { "", "one", "two", "three", "four",
"five", "six", "seven", "eight", "nine", "ten",
"eleven", "twelve", "thirteen", "fourteen", "fifteen",
"sixteen", "seventeen", "eighteen", "nineteen" };

char str[53];

int main(){

	num[20] = "twenty";
	num[30] = "thirty";
	num[40] = "forty";
	num[50] = "fifty";
	num[60] = "sixty";
	num[70] = "seventy";
	num[80] = "eighty";
	num[90] = "ninety";

	for (int i = 21; i <= 999; i++){
		if (num[i] != "")continue;
		int n = i;
		if (i >= 100){
			num[i] = num[i / 100];
			num[i] += "hundred";
		}
		n = i % 100;
		if (num[n] != "")num[i] += num[n];
		else{
			num[n] += num[i / 10 * 10];
			n %= 10;
			num[i] += num[n];
		}
	}

	int n;
	scanf("%d", &n);

	vector <string> ans;

	int len = 0;

	for (int i = 0; i < n; i++){
		scanf("%s", str);
		ans.push_back((string)str);
		len += ans.back().size();
		if (!strcmp(str, "$"))len--;
	}

	for (int i = 1; i <= 999; i++){
		int g = len + num[i].size();
		if (g == i){
			for (int j = 0; j < ans.size(); j++){
				if (ans[j] == "$")printf("%s ", num[i].c_str());
				else
					printf("%s ", ans[j].c_str());
			}
			break;
		}
	}

}