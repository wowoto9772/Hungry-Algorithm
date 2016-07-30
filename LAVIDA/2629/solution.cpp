#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

string I[53];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		vector <int>  L['z' + 1], R['z' + 1];
		vector <int> LR['z' + 1];

		string str;

		int top = 0;

		for (int i = 1; i <= n; i++){
			string tmp;
			cin >> tmp;

			bool flag = false;
			for (int k = 1; !flag && k < tmp.size(); k++){
				if (tmp[0] != tmp[k])flag = true;
			}

			char left = tmp[0], right = tmp[tmp.size() - 1];
			if (flag){
				L[left].push_back(top);
				R[right].push_back(top);
			}
			else{
				LR[left].push_back(top);
			}
			I[top++] = tmp;
		}

		bool used[53] = { 0 };

		vector <string> course;

		// Factoring
		bool impossible = false;

		for (int x = 0; x < top && !impossible; x++){
			str = "";
			if (used[x])continue;
			str = I[x];
			used[x] = true;

			while (true){
				char left = str[0], right = str[str.size() - 1];

				if (LR[right].size()){
					for (int j = 0; j < LR[right].size(); j++){
						if (used[LR[right][j]])continue;
						str = str + I[LR[right][j]];
						used[LR[right][j]] = true;
					}
					LR[right].clear();
				}
				if (LR[left].size()){
					for (int j = 0; j < LR[left].size(); j++){
						if (used[LR[left][j]])continue;
						str = I[LR[left][j]] + str;
						used[LR[left][j]] = true;
					}
					LR[left].clear();
				}

				if (L[right].size() > 1 || R[left].size() > 1){
					impossible = true;
					break;
				}

				bool nend = false;

				if (L[right].size()){
					if (!used[L[right][0]]){
						used[L[right][0]] = true;
						str = str + I[L[right][0]];
						nend = true;
					}
				}

				if (R[left].size()){
					if (!used[R[left][0]]){
						used[R[left][0]] = true;
						str = I[R[left][0]] + str;
						nend = true;
					}
				}

				if (!nend)break;
			}

			course.push_back(str);
		}

		if (!impossible){
			// reset

			top = 0;

			for (int i = 'a'; i <= 'z'; i++)L[i].clear(), R[i].clear();

			for (int i = 0; i < course.size(); i++){
				string tmp = course[i];

				bool flag = false;
				for (int k = 1; !flag && k < tmp.size(); k++){
					if (tmp[0] != tmp[k])flag = true;
				}

				char left = tmp[0], right = tmp[tmp.size() - 1];
				if (flag){
					L[left].push_back(top);
					R[right].push_back(top);
				}
				else{
					LR[left].push_back(top);
				}
				I[top++] = tmp;
			}

			for (int i = 0; i < top; i++)used[i] = false;

			course.clear();

			// Refactoring

			for (int x = 0; x < top && !impossible; x++){
				str = "";
				if (used[x])continue;
				str = I[x];
				used[x] = true;

				while (true){
					char left = str[0], right = str[str.size() - 1];

					if (LR[right].size()){
						for (int j = 0; j < LR[right].size(); j++){
							if (used[LR[right][j]])continue;
							str = str + I[LR[right][j]];
							used[LR[right][j]] = true;
						}
						LR[right].clear();
					}
					if (LR[left].size()){
						for (int j = 0; j < LR[left].size(); j++){
							if (used[LR[left][j]])continue;
							str = I[LR[left][j]] + str;
							used[LR[left][j]] = true;
						}
						LR[left].clear();
					}

					if (L[right].size() > 1 || R[left].size() > 1){
						impossible = true;
						break;
					}

					bool nend = false;

					if (L[right].size()){
						if (!used[L[right][0]]){
							used[L[right][0]] = true;
							str = str + I[L[right][0]];
							nend = true;
						}
					}

					if (R[left].size()){
						if (!used[R[left][0]]){
							used[R[left][0]] = true;
							str = I[R[left][0]] + str;
							nend = true;
						}
					}

					if (!nend)break;
				}

				course.push_back(str);
			}
		}

		string ans;
		bool MANY = false;
		// candidate for "MANY"
		if (course.size() > 1){
			MANY = true;
		}

		// Merge
		for (int j = 0; j < course.size(); j++){
			ans += course[j];
		}

		// check
		int k['z' + 1] = { 0 };
		for (int i = 0; i < ans.size(); i++)k[ans[i]]++;

		for (int i = 0; i < ans.size(); i++){
			k[ans[i]]--;
			if (i + 1 < ans.size()){
				if (ans[i] != ans[i + 1]){
					if (k[ans[i]])impossible = true;
				}
			}
			if (i == ans.size() - 1){
				if (k[ans[i]])impossible = true;
			}
		}

		if (impossible)printf("IMPOSSIBLE\n");
		else if (MANY)printf("MANY\n");
		else{
			cout << ans << endl;
		}
	}
}