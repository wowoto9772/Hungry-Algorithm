//#include <stdio.h>
//#include <string.h>
//
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		string str, tmp;
//		scanf("%s", tmp.c_str());
//		str = tmp.c_str();
//
//		string type;
//		int pos;
//
//		while (scanf("%s", type.c_str()) == 1 && type.c_str()[0] != 'E'){
//			if (type.c_str()[0] == 'I'){
//				scanf("%s %d", tmp.c_str(), &pos);
//				string ans = tmp.c_str();
//				str.insert(pos, ans);
//			}
//			else if (type.c_str()[0] == 'P'){
//				int a, b;
//				scanf("%d %d", &a, &b);
//				printf("%s\n", str.substr(a, b - a + 1).c_str());
//			}
//		}
//	}
//}

#include <stdio.h>
#include <string.h>

#include <string>
#include <iostream>

using namespace std;

char sstr[1000005];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		string str, tmp;
		scanf("%s", sstr);
		str = sstr;

		int pos;

		while (scanf("%s", sstr) == 1 && sstr[0] != 'E'){
			if (sstr[0] == 'I'){
				scanf("%s %d", sstr, &pos);
				str.insert(pos, sstr);
			}
			else if (sstr[0] == 'P'){
				int a, b;
				scanf("%d %d", &a, &b);
				printf("%s\n", str.substr(a, b - a + 1).c_str());
			}
		}
	}
}