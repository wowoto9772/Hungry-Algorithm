/*
Real numbers may have a decimal point.
an exponent(starting with the character e or E) may have a decimal point.

If there is a decimal point, there must be 
at least one digit on each side of the point.

There may be a plus or minus sign in front of the number.
There may be a plus or minus sign in front of the exponent.
or both (without any blank characters after the sign)

Exponents are integers (not having decimal points)

There may be blank characters before or after a number, but not inside it
number 안에는 공백이 잇어서는 안된다.

you may assume the input strings are not longer than 1000 characters.
*/

#include <string.h>
#include <stdio.h>

#define init 0
#define digit 1
#define exp 2
#define dots 3
#define flag 4

int stm[5][5]; // state machine

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		char str[1005] = { 0 };
		scanf("%s", str);

		int s = strlen(str);

		int state = init; // start

		bool isLEGAL = true;
		bool predots = false;
		bool preexp = false;

		for (int i = 0; isLEGAL && i < s; i++){
			if ('0' <= str[i] && str[i] <= '9'){
				state = digit;
			}
			else if ('e' == str[i] || str[i] == 'E'){
				if (state == flag || state == dots || state == exp)isLEGAL = false;
				if(!preexp)preexp = true;
				state = exp;
			}
			else if ('.' == str[i]){
				if (state == init || state == dots)isLEGAL = false;
				if (!predots)predots = true;
				else
					isLEGAL = false;
				if (preexp)isLEGAL = false;
				state = dots;
			}
			else if ('+' == str[i] || str[i] == '-'){
				if (state == dots)isLEGAL = false;
				state = flag;
			}
		}

		if (state == dots || state == flag)isLEGAL = false;

		if (isLEGAL)printf("LEGAL\n");
		else
			printf("ILLEGAL\n");
	}

}