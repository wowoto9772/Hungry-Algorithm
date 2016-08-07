#include <stdio.h>
#include <string.h>

char str[18][18];
char cmd[53];

class player {
public:

	int r, c;

	player() {}
	player(int _r, int _c) { r = _r, c = _c; }

	bool operator==(const player &A)const {

		return r == A.r && c == A.c;

	}

};

int r, c;

bool isEnded() {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (str[i][j] == '+')return false;
			else if (str[i][j] == 'W')return false;
		}
	}

	return true;

}

player nextPosition(player cur, char nxt) {

	player ret = cur;

	if (nxt == 'L') {
		ret.c--;
	}
	else if (nxt == 'R') {
		ret.c++;
	}
	else if (nxt == 'U') {
		ret.r--;
	}
	else if (nxt == 'D') {
		ret.r++;
	}

	if (ret.c < 0 || ret.c >= c || ret.r >= r || ret.r < 0
		|| str[ret.r][ret.c] == '#')ret = cur;

	return ret;

}

int main() {

	int tc = 0;

	while (scanf("%d %d", &r, &c) == 2) {

		if (!(r | c))break;

		tc++;

		player me;

		for (int i = 0; i < r; i++) {
			scanf("%s", str[i]);
			for (int j = 0; j < c; j++) {
				if (str[i][j] == 'w' || str[i][j] == 'W')me = { i, j };
			}
		}

		scanf("%s", cmd);

		int s = strlen(cmd);

		for (int i = 0; i < s && !isEnded(); i++) {

			player nme = nextPosition(me, cmd[i]);

			if (me == nme)continue;
			else {

				int np = str[nme.r][nme.c];

				if (np == 'b' || np == 'B') {

					player nnme = nextPosition(nme, cmd[i]);

					if (nme == nnme)continue;
					else {

						char nnp = str[nnme.r][nnme.c];

						if (nnp == 'b' || nnp == 'B')continue;

						if (nnp == '+') {
							str[nnme.r][nnme.c] = 'B';
						}
						else if (nnp == '.') {
							str[nnme.r][nnme.c] = 'b';
						}

						if (np == 'B') {
							str[nme.r][nme.c] = 'W';
						}
						else {
							str[nme.r][nme.c] = 'w';
						}

					}
				}
				else {

					if (np == '+') {
						str[nme.r][nme.c] = 'W';
					}
					else {
						str[nme.r][nme.c] = 'w';
					}

				}

				char cp = str[me.r][me.c];

				if (cp == 'W') {
					str[me.r][me.c] = '+';
				}
				else {
					str[me.r][me.c] = '.';
				}

			}

			me = nme;

		}

		printf("Game %d: ", tc);

		if (isEnded()) {
			printf("complete\n");
		}
		else {
			printf("incomplete\n");
		}

		for (int i = 0; i < r; i++)printf("%s\n", str[i]);

	}

}