#include <stdio.h>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BigInteger {
public:
	vector<int> num;
	BigInteger() {}
	BigInteger(string s) {
		bool flag = false;
		for (int i = 0; !flag && i < s.size(); i++) {
			if (s[i] != '0') {
				s = s.substr(i);
				flag = true;
			}
		}
		if (!flag)s = '0';

		reverse(s.begin(), s.end());
		num.resize(s.size());
		for (int i = 0; i < s.size(); i++) {
			num[i] = s[i] - '0';
		}
		refine();
	}

	string toString() {
		string ret(num.size(), '0');
		for (int i = num.size() - 1, j = 0; i >= 0; j++, i--) {
			ret[j] = num[i] + '0';
		}
		return ret;
	}

	void refine() {
		for (int i = 0; i < num.size() - 1; i++) {
			if (num[i] < 0) {
				num[i] += 10;
				num[i + 1]--;
			}
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
		if ((num.back() / 10) > 0) {
			num.push_back(num.back() / 10);
			num[num.size() - 2] %= 10;
		}
		int st;
		for (int i = num.size() - 1; i >= 0; i--) {
			st = i;
			if (num[i] != 0) break;
		}
		num.resize(st + 1);
	}

	BigInteger operator+ (const BigInteger &a) { // compute a+b
		BigInteger ret;
		vector<int> &res = ret.num;
		res = vector<int>(num);
		res.resize(max(num.size(), a.num.size()), 0);
		for (int i = 0; i < a.num.size(); i++)
			res[i] += a.num[i];
		for (int i = 0; i < res.size() - 1; i++) {
			res[i + 1] += res[i] / 10;
			res[i] %= 10;
		}
		ret.refine();
		return ret;
	}
};

BigInteger dp[103][103];
int a[103][103];
int n;

BigInteger dy(int i, int j) {

	if (i == n - 1 && j == n - 1)return BigInteger("1");

	if (dp[i][j].toString() != "-1")return dp[i][j];

	dp[i][j] = BigInteger("0");

	int d = a[i][j];

	if (i + d < n)dp[i][j] = dp[i][j] + dy(i + d, j);
	if (j + d < n)dp[i][j] = dp[i][j] + dy(i, j + d);

	return dp[i][j];

}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			dp[i][j] = BigInteger("-1");
		}
	}

	printf("%s\n", dy(0, 0).toString().c_str());
}