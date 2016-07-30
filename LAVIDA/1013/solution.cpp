//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <string.h>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//string str[53];
//const string ques = "??????????????????????????????????????????????????";
//
//void swp(string *a, string *b){
//	string tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n;
//		scanf("%d", &n);
//
//		bool chk[53][53] = { 0 };
//
//		for (int i = 0; i < n; i++)cin >> str[i];
//
//		int s = str[0].size();
//
//		int in[53] = { 0 };
//
//		for (int i = 0; i < n; i++){
//			for (int j = i + 1; j < n; j++){
//				bool flag = false;
//				for (int k = 0; k < s; k++){
//					if (str[i][k] == '?' || str[j][k] == '?')continue;
//					if (str[i][k] > str[j][k]){
//						flag = true;
//						swp(&str[i], &str[j]);
//						break;
//					}
//				}
//				if (!flag){
//					for (int k = 0; k < s; k++){
//						if (str[i][k] == 'A' && str[j][k] == '?')continue;
//						if (str[i][k] == '?' && str[j][k] == 'A'){
//							swp(&str[i], &str[j]);
//							break;
//						}
//						else if (str[i][k] != '?' && str[j][k] == '?'){
//							swp(&str[i], &str[j]);
//							break;
//						}
//					}
//				}
//			}
//		}
//
//
//		for (int i = 0; i < n; i++){
//			for (int j = 0; j < n; j++){
//				if (i == j)continue;
//				else{
//					bool conf = false;
//					for (int k = 0; k < s; k++){
//						if (str[i][k] == '?' || str[j][k] == '?')continue;
//						if (str[i][k] < str[j][k]){
//							chk[i][j] = true;
//							in[j]++;
//							break;
//						}
//					}
//				}
//			}
//		}
//
//		queue <int> q;
//		bool used[53] = { 0 };
//
//		for (int i = 0; i < n; i++){ // all question marks
//			//cout << str[i] << endl;
//			if (!strncmp(str[i].c_str(), ques.c_str(), s)){
//				q.push(i);
//				used[i] = true;
//			}
//		}
//
//		for (int i = 0; i < n; i++){
//			if (!used[i] && !in[i]){
//				q.push(i);
//				used[i] = true;
//			}
//		}
//
//		string stable = "";
//		string ans[53];
//
//		int top = 0;
//
//		while (!q.empty()){
//			int f = q.front(); q.pop();
//			if (stable == ""){
//				for (int i = 0; i < s; i++){
//					stable += str[f][i];
//					if (stable[i] == '?')stable[i] = 'A';
//				}
//				ans[top++] = stable;
//			}
//			else{
//				bool flag = false;
//				for (int i = 0; i < s; i++){
//					if (str[f][i] != '?' && stable[i] > str[f][i]){
//						flag = true;
//						break;
//					}
//					char tmp = stable[i];
//					stable[i] = str[f][i];
//					if (str[f][i] == '?')stable[i] = tmp;
//					if (stable[i] == '?')stable[i] = 'A';
//				}
//				if(!flag)ans[top++] = stable;
//				else{
//					break;
//				}
//			}
//			for (int i = 0; i < n; i++){
//				if (chk[f][i]){
//					in[i]--;
//				}
//				if (!used[i] && !in[i]){
//					used[i] = true;
//					q.push(i);
//				}
//			}
//		}
//
//		if (top != n)printf("impossible\n");
//		else{
//			for (int i = 0; i < top; i++)cout << ans[i] << endl;
//		}
//	}
//}
//
///*
//3
//?AE?
//B???
//???E
//
//4
//????E?D
//???CF??
//??A?E??
//A?A??A?
//
//AAAAAAA
//AAAAEAA
//AAAAEAD
//AAACFAD
//
//3
//????A?
//B?????
//??????
//*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

string str[53];
const string smin = "[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[";

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		bool chk[53][53] = { 0 };

		for (int i = 0; i < n; i++)cin >> str[i];

		int s = str[0].size();

		int in[53] = { 0 };

		bool cyc[53][53] = { 0 };

		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i == j)continue;
				else{
					for (int k = 0; k < s; k++){
						if (str[i][k] == '?' || str[j][k] == '?')continue;
						if (str[i][k] < str[j][k]){
							chk[i][j] = true;
							cyc[i][j] = true;
							in[j]++;
							break;
						}
					}
				}
			}
		}

		for (int k = 0; k < n; k++){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					cyc[i][j] = cyc[i][k] & cyc[k][j] == true ? true : cyc[i][j];
				}
			}
		}

		bool flag = false;
		for (int i = 0; i < n; i++){
			if (cyc[i][i]){
				flag = true;
				break;
			}
		}

		if (flag)printf("impossible\n");
		else{
			queue <int> q;
			bool used[53] = { 0 };

			int x = -1;
			string tmin = smin;
			for (int i = 0; i < n; i++){
				if (!in[i]){
					string tstable = str[i];

					for (int j = 0; j < s; j++){
						char tmp = tstable[j];
						tstable[j] = str[i][j];
						if (str[i][j] == '?')tstable[j] = tmp;
						if (tstable[j] == '?')tstable[j] = 'A';
					}

					if (tmin > tstable){
						tmin = tstable;
						x = i;
					}
				}
			}

			used[x] = true;
			q.push(x);

			string stable = "";
			for (int i = 0; i < s; i++)stable += '?';

			int top = 0;

			while (!q.empty()){
				int f = q.front(); q.pop();

				for (int i = 0; i < s; i++){
					char tmp = stable[i];
					stable[i] = str[f][i];
					if (str[f][i] == '?')stable[i] = tmp;
					if (stable[i] == '?')stable[i] = 'A';
				}

				cout << stable << endl;

				string tmin = smin;
				int x = -1;
				for (int i = 0; i < n; i++){
					if (chk[f][i]){
						in[i]--;
					}
					if (!used[i] && !in[i]){
						string tstable = stable;

						for (int j = 0; j < s; j++){
							char tmp = tstable[j];
							tstable[j] = str[i][j];
							if (str[i][j] == '?')tstable[j] = tmp;
							if (tstable[j] == '?')tstable[j] = 'A';
						}

						if (tmin > tstable){
							tmin = tstable;
							x = i;
						}
					}
				}

				if (x == -1)continue;
				used[x] = true;
				q.push(x);
			}
		}
	}
}

/*
3
?AE?
B???
???E

4
????E?D
???CF??
??A?E??
A?A??A?

3
????A?
B?????
??????
*/