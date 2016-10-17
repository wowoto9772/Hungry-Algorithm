#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

// result = kmp::match(text, pattern); // integer vector of all match point
namespace kmp
{
	typedef vector<int> seq_t;
	void calculate_pi(vector<int>& pi, const seq_t& str) {
		pi[0] = -1;
		int j = -1;
		for (int i = 1; i < str.size(); i++) {
			while (j >= 0 && str[i] != str[j + 1]) j = pi[j];
			if (str[i] == str[j + 1])
				pi[i] = ++j;
			else
				pi[i] = -1;
		}
	}
	vector<int> match(seq_t text, seq_t pattern) {
		vector<int> pi(pattern.size());
		vector<int> ans;
		if (pattern.size() == 0) return ans;
		calculate_pi(pi, pattern);
		int j = -1;
		for (int i = 0; i < text.size(); i++) {
			while (j >= 0 && text[i] != pattern[j + 1]) j = pi[j];
			if (text[i] == pattern[j + 1]) {
				j++;
				if (j + 1 == pattern.size()) {
					ans.push_back(i - j);
					j = pi[j];
				}
			}
		}
		return ans;
	}
} // namespace kmp

char _str[2003];
char _A[2003], _B[2003];

int main(){

    scanf("%s %s %s", _str, _A, _B);

    int s = strlen(_str);

    vector <int> str(s);
    for(int i=0; i<s; i++)str[i] = _str[i];
    s = strlen(_A);
    vector <int> A(s);
    for(int i=0; i<s; i++)A[i] = _A[i];
    s = strlen(_B);
    vector <int> B(s);
    for(int i=0; i<s; i++)B[i] = _B[i];

    vector <int> matchA = kmp::match(str, A);
    vector <int> matchB = kmp::match(str, B);

    int ans = 0;

    for(auto mA : matchA){
        for(auto mB : matchB){
            if(mA+A.size()-1 <= mB)ans++;
        }
    }

    printf("%d\n", ans);

}
