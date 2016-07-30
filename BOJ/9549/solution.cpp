/*
1.
Swap two different characters of the given password 
(you can do this step zero or more times).

2. Append zero or more lower case English letters 
at the beginning of the output of step one.

3. Append zero or more lower case English letters
to the end of the output of step two.
*/

#include <stdio.h>
#include <string.h>

char enc[100003], org[100003];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%s %s", enc, org);


		int s = strlen(org), r = 0, Or;
		Or = r = s;

		int c['z' + 2] = { 0 };
		int Oc['z' + 2] = { 0 };
		for (int i = 0; i < s; i++){
			c[org[i]]++;
			Oc[org[i]]++;
		}

		// 26 * 100000

		s = strlen(enc);

		bool flag = false;

		int p = -1;

		for (int i = 0; !flag && i < s; i++){
			if (Oc[enc[i]] == 0){
				p = -1;
				r = Or;
				for (int j = 'a'; j <= 'z'; j++)c[j] = Oc[j];
				continue;
			}
			if (c[enc[i]] > 0){
				if (p == -1)p = i;
				c[enc[i]]--;
				r--;
				if (!r)flag = true;
			}
			else{
				while (!c[enc[i]] && p < i){
					c[enc[p]]++;
					r++;
					p++;
				}

				if (c[enc[i]]){
					c[enc[i]]--;
					r--;
				}
				if (!r)flag = true;
			}
		}

		if (flag)printf("YES\n");
		else{
			printf("NO\n");
		}
	}
}