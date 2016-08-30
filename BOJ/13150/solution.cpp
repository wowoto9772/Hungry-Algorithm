#include <stdio.h>
#include <vector>
#include <string>

#include <algorithm>

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

		bool operator < (const BigInteger &comp)const{
			if (num.size() < comp.num.size()) return true;
			if (num.size() > comp.num.size()) return false;
			for (int i = num.size() - 1; i >= 0; i--) if (num[i] != comp.num[i]) return num[i] < comp.num[i];
			return false;
		}

		bool operator <= (const BigInteger &comp)const{
			if (num.size() < comp.num.size()) return true;
			if (num.size() > comp.num.size()) return false;
			for (int i = num.size() - 1; i >= 0; i--) if (num[i] != comp.num[i]) return num[i] <= comp.num[i];
			return true;
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

		BigInteger operator- (const BigInteger &a){ // if a >= b, then compute a-b
			BigInteger ret;
			vector <int> &res = ret.num;
			res = vector<int>(num);
			res.resize(max(num.size(), a.num.size()), 0);

			for (int i = 0; i < min(num.size(), a.num.size()); i++){
				ret.num[i] = num[i] - a.num[i];
			}
			ret.refine();
			return ret;
		}

		BigInteger operator* (const BigInteger &a){ // compute a*b
			BigInteger ret;
			vector<int> &res = ret.num;
			res.resize(num.size() + a.num.size(), 0);
			for (int i = 0; i < num.size(); i++){
				for (int j = 0; j < a.num.size(); j++){
					res[i + j] += num[i] * a.num[j];
				}
			}
			ret.refine();
			return ret;
		}

		BigInteger operator/ (BigInteger &a){ // if b != 0, then compute a/b
			string very_big;
			for (int i = 1; i <= 120; i++)very_big += "9";
			BigInteger dvnd(toString());
			BigInteger dvs(a.toString());
			BigInteger l("0"), r(very_big), q;

			int c = 0;
			while (l <= r){
				q = (l + r);
				q.divide_two();

				BigInteger cmp = q*dvs;
				if (dvnd < cmp)r = q - BigInteger("1");
				else{
					l = q + BigInteger("1");
				}
				c++;
			}

			if (!(q*dvs <= dvnd))q = q - BigInteger("1");

			return q;
		}


		BigInteger operator% (BigInteger &a){ // if b != 0, then compute a%b
			string very_big;
			for (int i = 1; i <= 120; i++)very_big += "9";
			BigInteger dvnd(toString());
			BigInteger dvs(a.toString());
			BigInteger l("0"), r(very_big), q;

			int c = 0;
			while (l <= r){
				q = (l + r);
				q.divide_two();

				BigInteger cmp = q*dvs;
				if (dvnd < cmp)r = q - BigInteger("1");
				else{
					l = q + BigInteger("1");
				}
				c++;
			}

			if (!(q*dvs <= dvnd))q = q - BigInteger("1");

			BigInteger R = dvnd - q * dvs;
			return R;
		}
};


BigInteger a[2][2];

char str[80];

int main(){

	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			scanf("%s", str);
			string _str = string(str);
			a[i][j] = BigInteger(_str);
		}
	}

	string ans;

	while(true){

		if(a[0][0].num.size() == 1 && a[0][0].num.back() == 1 &&
				a[1][1].num.size() == 1 && a[1][1].num.back() == 1 &&
				a[0][1].num.size() == 1 && a[0][1].num.back() == 0 &&
				a[1][0].num.size() == 1 && a[1][0].num.back() == 0){
			break;
		}else{
			if(a[0][1] < a[0][0]){
				a[0][0] = a[0][0] - a[0][1];
				a[1][0] = a[1][0] - a[1][1];
				ans += "0";
			}else{
				a[0][1] = a[0][1] - a[0][0];
				a[1][1] = a[1][1] - a[1][0];
				ans += "1";
			}
			printf("occured");
		}

		printf("%s %s\n", a[0][0].toString().c_str(), a[0][1].toString().c_str());
		printf("%s %s\n", a[1][0].toString().c_str(), a[1][1].toString().c_str());
	}

	reverse(ans.begin(), ans.end());

	printf("%s\n", ans.c_str());

}
