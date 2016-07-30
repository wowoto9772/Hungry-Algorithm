#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string dp[253] = { "1", "1", "3" };

class BigInteger{
public:
	vector<int> num;
	BigInteger(){}
	BigInteger(string s){
		reverse(s.begin(), s.end());
		num.resize(s.size());
		for (int i = 0; i<s.size(); i++){
			num[i] = s[i] - '0';
		}
		refine();
	}

	string toString(){
		string ret(num.size(), '0');
		for (int i = num.size() - 1, j = 0; i >= 0; j++, i--){
			ret[j] = num[i] + '0';
		}
		return ret;
	}

	int max(int a, int b){ return a < b ? b : a; }

	void refine(){
		for (int i = 0; i<num.size() - 1; i++){
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
		if ((num.back() / 10)>0){
			num.push_back(num.back() / 10);
			num[num.size() - 2] %= 10;
		}
		int st;
		for (int i = num.size() - 1; i >= 0; i--){
			st = i;
			if (num[i] != 0) break;
		}
		num.resize(st + 1);
	}

	BigInteger operator* (const BigInteger &a){
		BigInteger ret;
		vector<int> &res = ret.num;
		res.resize(num.size() + a.num.size(), 0);
		for (int i = 0; i<num.size(); i++){
			for (int j = 0; j<a.num.size(); j++){
				res[i + j] += num[i] * a.num[j];
			}
		}
		ret.refine();
		return ret;
	}

	BigInteger operator+ (const BigInteger &a){
		BigInteger ret;
		vector<int> &res = ret.num;
		res = vector<int>(num);
		res.resize(max(num.size(), a.num.size()), 0);
		for (int i = 0; i<a.num.size(); i++)
			res[i] += a.num[i];
		for (int i = 0; i<res.size() - 1; i++){
			res[i + 1] += res[i] / 10;
			res[i] %= 10;
		}
		ret.refine();
		return ret;
	}
};

int main()
{
	for (int i = 3; i <= 250; i++){
		BigInteger dp_2(dp[i - 2]);
		BigInteger dp_1(dp[i - 1]);
		BigInteger two("2");
		dp[i] = (dp_2 * two + dp_1).toString();
	}

	int n;
	while (scanf("%d", &n) == 1){
		cout << dp[n] << endl;
	}
}