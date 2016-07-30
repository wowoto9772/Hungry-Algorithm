#include <stdio.h>
#include <string.h>

#include <iostream>
#include <vector>

using namespace std;

class men{
public:
	int T; // 1 : Student, 2 : Professor, 3 : Faculty
	int isN, C;
	bool removed;
	char name[5], isW[4];
};

bool charged[1000000];
int pos[1000000];

int S(int a){
	int ret = 0;
	while (a / 10){
		ret++;
		a /= 10;
	}
	ret++;
	return ret;
}

int main()
{
	vector <men> DAT;


	while (true){
		char stri[100] = { 0 };
		while (!strcmp(stri, ""))gets(stri);
		char str[100] = { 0 }, str2[100] = { 0 }, str3[100] = { 0 }, str4[100] = { 0 }, str5[100];
		sscanf(stri, "%s %s %s %s %s\n", str, str2, str3, str4, str5);
		//printf("%s %s %s %s %s %s\n", str, str2, str3, str4, str5);

		int t, s, n;
		bool flag = false;

		if (!strcmp(str, "ADD")){
			s = strlen(stri);
			if (s != 19)flag = true;
			else{
				men psh;

				if (!strcmp(str2, "S")){
					psh.T = 1;
				}
				else if (!strcmp(str2, "P")){
					psh.T = 2;
				}
				else if (!strcmp(str2, "F")){
					psh.T = 3;
				}
				else{
					flag = true;
				}

				s = strlen(str3);
				if (s != 3)flag = true;
				else{
					for (int i = 0; i<3; i++)if (str3[i] < 'A' || str3[i] > 'Z')flag = true;
					if (!flag){
						strcpy(psh.name, str3);

						s = strlen(str4);
						if (s != 6)flag = true;
						else{
							for (int i = 0; i<6; i++)if (str4[i] < '0' || str4[i] > '9')flag = true;
							if (!flag){
								n = 0;
								for (int i = 0; i<6; i++){
									n = n * 10 + str4[i] - '0';
								}
								if (charged[n]){
									flag = true;
								}
								else{
									psh.isN = n;

									charged[n] = true;

									s = strlen(str5);
									if (s != 2){
										flag = true;
									}
									else{
										for (int i = 0; i<2; i++)if (str5[i] < 'A' || str5[i] > 'Z')flag = true;
										if (!flag){
											strcpy(psh.isW, str5);
											psh.C = 0;
											psh.removed = false;

											pos[n] = DAT.size();
											DAT.push_back(psh);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else if (!strcmp(str, "SHOWALL")){
			s = strlen(stri);
			if (s != 7)flag = true;
			else{
				for (int i = 0; i<DAT.size(); i++){
					if (DAT[i].removed)continue;

					t = DAT[i].T;
					string pr;
					if (t == 1)printf("Student : ");
					else if (t == 2)printf("Professor : ");
					else
						printf("Faculty : ");

					printf("%s %06d %s", DAT[i].name, DAT[i].isN, DAT[i].isW);

					if (t != 3){
						printf(" %d", DAT[i].C);
					}printf("\n");
				}
			}
		}
		else if (!strcmp(str, "SHOWDIV")){
			s = strlen(stri);
			if (s != 10)flag = true;
			else{
				s = strlen(str2);
				if (s != 2)flag = true;
				else{
					for (int i = 0; i<2; i++)if (str2[i] < 'A' || str2[i] > 'Z')flag = true;
					if (!flag){
						for (int i = 0; i<DAT.size(); i++){
							if (DAT[i].removed)continue;

							if (!strcmp(DAT[i].isW, str2)){
								t = DAT[i].T;
								string pr;
								if (t == 1)printf("Student : ");
								else if (t == 2)printf("Professor : ");
								else
									printf("Faculty : ");
								printf("%s %06d %s", DAT[i].name, DAT[i].isN, DAT[i].isW);
								if (t != 3){
									printf(" %d", DAT[i].C);
								}printf("\n");
							}
						}
					}
				}
			}
		}
		else if (!strcmp(str, "DEL")){
			s = strlen(stri);
			if (s != 10)flag = true;
			else{
				s = strlen(str2);
				if (s != 6)flag = true;
				else{
					for (int i = 0; i<6; i++)if (str2[i] < '0' || str2[i] > '9')flag = true;
					if (!flag){
						n = 0;
						for (int i = 0; i<6; i++){
							n = n * 10 + str2[i] - '0';
						}
						if (!charged[n])flag = true;
						else{
							//DAT.erase(DAT.begin() + pos[n]);
							DAT[pos[n]].removed = true;
							pos[n] = 0;
							charged[n] = false;
						}
					}
				}
			}
		}
		else if (!strcmp(str, "ADD_COURSE")){
			s = strlen(stri);
			if (s != 23)flag = true;
			else{
				s = strlen(str2);
				if (s != 6)flag = true;
				else{
					for (int i = 0; i<6; i++)if (str2[i] < '0' || str2[i] > '9')flag = true;
					if (!flag){
						n = 0;
						for (int i = 0; i<6; i++){
							n = n * 10 + str2[i] - '0';
						}
						if (!charged[n]){
							flag = true;
						}
						else{
							s = strlen(str3);
							if (s != 5)flag = true;
							else{
								for (int i = 0; i <= 1; i++)if (str3[i] < 'A' || str3[i] > 'Z')flag = true;
								for (int i = 2; i<5; i++)if (str3[i] < '0' || str3[i] > '9')flag = true;
								if (!flag){
									DAT[pos[n]].C++;
								}
							}
						}
					}
				}
			}
		}
		else if (!strcmp(str, "END")){
			s = strlen(stri);
			if (s != 3)flag = true;
			else{
				break;
			}
		}

		if (flag)cout << "Error!" << endl;
	}
}