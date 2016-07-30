#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


class BigInteger{
public:
	vector<int> num;
	BigInteger(){}
	BigInteger(string s){
		bool flag = false;
		for (int i = 0; !flag && i < s.size(); i++){
			if (s[i] != '0'){
				s = s.substr(i);
				flag = true;
			}
		}
		if (!flag)s = '0';

		reverse(s.begin(), s.end());
		num.resize(s.size());
		for (int i = 0; i < s.size(); i++){
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

	void refine(){
		for (int i = 0; i < num.size() - 1; i++){
			if (num[i] < 0){
				num[i] += 10;
				num[i + 1]--;
			}
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
		if ((num.back() / 10) > 0){
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

	void divide_two(){
		reverse(num.begin(), num.end());
		for (int i = 0; i < num.size(); i++){
			int k = num[i] % 2;
			if (k){
				if (i < num.size() - 1)num[i + 1] += 10;
			}
			num[i] /= 2;
		}
		reverse(num.begin(), num.end());
		for (int i = num.size() - 1; i >= 0; i--){
			if (num[i])break;
			else{
				num.pop_back();
			}
		}
		if (!num.size())num.push_back(0);
	}

	BigInteger operator+ (const BigInteger &a){ // compute a+b
		BigInteger ret;
		vector<int> &res = ret.num;
		res = vector<int>(num);
		res.resize(max(num.size(), a.num.size()), 0);
		for (int i = 0; i < a.num.size(); i++)
			res[i] += a.num[i];
		for (int i = 0; i < res.size() - 1; i++){
			res[i + 1] += res[i] / 10;
			res[i] %= 10;
		}
		ret.refine();
		return ret;
	}

};

char a[10003], b[10003];

int main(){
	scanf("%s %s", a, b);

	BigInteger A(a), B(b);
	A = A + B;
	printf("%s\n", A.toString().c_str());
}
