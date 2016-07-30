//#include <stdio.h>
//#include <string.h>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//class ele{
//public:
//	string lname, fname;
//	string orglname, orgfname;
//	bool operator<(const ele &A)const{
//		if (orglname.size() >= A.orglname.size() || orglname.size() < A.orglname.size() && A.orglname.substr(0, orglname.size()) != orglname){
//			if (lname == A.lname){
//				if (orglname == A.orglname){
//					if (orgfname.size() >= A.orgfname.size() || orgfname.size() < A.orgfname.size() && A.orgfname.substr(0, orgfname.size()) != orgfname){
//						if (fname == A.fname)return orgfname > A.orgfname;
//						return fname > A.fname;
//					}
//					else{
//						if (orgfname.size() < A.orgfname.size() && A.orgfname.substr(0, orgfname.size()) == orgfname){
//							return orgfname.size() > A.orgfname.size();
//						}
//
//						if (fname == A.fname)return orgfname > A.orgfname;
//						return fname > A.fname;
//					}
//				}
//				return orglname < A.orglname;
//			}
//			return lname < A.lname;
//		}
//		else{
//			if (orglname.size() < A.orglname.size() && A.orglname.substr(0, orglname.size()) == orglname){
//				return orglname.size() < A.orglname.size();
//			}
//			else{
//				if (lname == A.lname){
//					if (orglname == A.orglname){
//						if (orgfname.size() >= A.orgfname.size() || orgfname.size() < A.orgfname.size() && A.orgfname.substr(0, orgfname.size()) != orgfname){
//							if (fname == A.fname)return orgfname > A.orgfname;
//							return fname > A.fname;
//						}
//						else{
//							if (orgfname.size() < A.orgfname.size() && A.orgfname.substr(0, orgfname.size()) == orgfname){
//								return orgfname.size() > A.orgfname.size();
//							}
//							else{
//								if (fname == A.fname)return orgfname > A.orgfname;
//								return fname > A.fname;
//							}
//						}
//					}
//					return orglname < A.orglname;
//				}
//				return lname < A.lname;
//			}
//		}
//	}
//}I[10003];
//
//int main(){
//	freopen("test.in", "r", stdin);
//
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n, k;
//		scanf("%d %d", &n, &k);
//
//		for (int i = 0; i < n; i++){
//
//			// data setting
//
//			I[i].fname = I[i].lname = I[i].orgfname = I[i].orglname = "";
//
//			char str[55] = { 0 };
//			while (!strcmp(str, ""))gets(str);
//
//			int s = strlen(str);
//			int c = 0;
//			for (int j = 0; j < s; j++){
//				if (str[j] == ' ')c++;
//			}
//			for (int j = 0; j < s; j++){
//				if (str[j] == ' ')c--;
//				if (c >= 1)I[i].fname += str[j]; // first name
//				else{
//					if (str[j] == ' ')continue;
//					I[i].lname += str[j]; // last name
//				}
//			}
//
//			I[i].orgfname = I[i].fname;
//			I[i].orglname = I[i].lname;
//
//			for (int j = 0; j < I[i].fname.size(); j++){ // high to low
//				if ('A' <= I[i].fname[j] && I[i].fname[j] <= 'Z')I[i].fname[j] += 'a' - 'A';
//			}
//			for (int j = 0; j < I[i].lname.size(); j++){ // low to high
//				if (I[i].lname[j] >= 'a')I[i].lname[j] -= 'a' - 'A';
//			}
//		}
//
//		sort(I, I + n);
//
//		printf("%s %s\n", I[k - 1].orgfname.c_str(), I[k - 1].orglname.c_str());
//	}
//}

#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

class ele{
public:
	string lname, fname;
	bool operator<(const ele &A)const{
		int s = lname.size();
		int as = A.lname.size();
		for (int i = 0; i < min(s, as); i++){
			int low = lname[i];
			int alow = A.lname[i];
			if (low >= 'a'){
				low -= 'a' - 'A';
			}
			if (alow >= 'a'){
				alow -= 'a' - 'A';
			}
			if (low != alow){
				return low < alow;
			}
			else{
				if (lname[i] == A.lname[i]){
					continue;
				}
				return lname[i] < A.lname[i];
			}
		}

		if (lname.size() == A.lname.size()){
			s = fname.size();
			as = A.fname.size();
			for (int i = 0; i < min(s, as); i++){
				int high = fname[i];
				int ahigh = A.fname[i];
				if (high >= 'A' && high <= 'Z'){
					high += 'a' - 'A';
				}
				if (ahigh >= 'A' && ahigh <= 'Z'){
					ahigh += 'a' - 'A';
				}
				if (high != ahigh){
					return high > ahigh;
				}
				else{
					if (fname[i] == A.fname[i]){
						continue;
					}
					return fname[i] > A.fname[i];
				}
			}
			return fname.size() > A.fname.size(); // prefix
		}
		return lname.size() < A.lname.size(); // prefix
	}
}I[10003];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, k;
		scanf("%d %d", &n, &k);

		for (int i = 0; i < n; i++){

			// data setting

			I[i].fname = I[i].lname = "";

			char str[55] = { 0 };
			while (!strcmp(str, ""))gets(str);

			int s = strlen(str);
			int c = 0;
			for (int j = 0; j < s; j++){
				if (str[j] == ' ')c++;
			}
			for (int j = 0; j < s; j++){
				if (str[j] == ' ')c--;
				if (c >= 1)I[i].fname += str[j]; // first name
				else{
					if (str[j] == ' ')continue;
					I[i].lname += str[j]; // last name
				}
			}
		}

		sort(I, I + n);

		printf("%s %s\n", I[k - 1].fname.c_str(), I[k - 1].lname.c_str());
	}
}