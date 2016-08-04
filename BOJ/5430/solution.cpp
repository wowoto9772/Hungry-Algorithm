#include <stdio.h>
#include <string.h>

#include <string>
#include <vector>

#include <algorithm>

using namespace std;

char cmd[100003];

char sstr[600003];
int n;


int main() {

	int t;
	scanf("%d", &t);

	while (t--)
	{


		vector < int > vv;

		scanf("%s", cmd);

		scanf("%d", &n);

		scanf("%s", sstr);

		int len = strlen(sstr);
		for (int i = 0; i < len; ++i)
			if (sstr[i] == ',' || sstr[i] == '[' || sstr[i] == ']')
				sstr[i] = ' ';

		int v = 0;

		for (int i = 0; i < len; ++i)
		{
			if (sstr[i] == ' ') {
				if(v > 0)vv.push_back(v);
				v = 0;
			}
			else {
				v = v * 10 + sstr[i] - '0';
			}
		}


		len = strlen(cmd);

		bool rev = false;
		bool err = true;

		int l = 0, r = n - 1;

		for (int i = 0; i < len; i++)
		{
			if (cmd[i] == 'R')
			{
				rev ^= true;
			}
			else  if (cmd[i] == 'D')
			{
				if (!rev)
				{
					if (l <= r)l++;
					else
					{
						err = false;
						break;
					}
				}
				else
				{
					if (l <= r)r--;
					else
					{
						err = false;
						break;
					}
				}
			}
		}

		if (err)
		{
			printf("[");
			if (rev)
			{
				for (int i=r; i>=l; i--)
				{
					if (i != r)printf(",");
					printf("%d", vv[i]);
				}
			}
			else
			{
				for (int i=l; i<=r; i++)
				{
					if (i != l)printf(",");
					printf("%d", vv[i]);
				}
			}
			printf("]");
		}
		else
			printf("error");

		printf("\n");
	}

	return 0;
}