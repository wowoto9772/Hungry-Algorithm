//#include <stdio.h>
//
//class point{
//public:
//	int x, y;
//};
//
//int CCW(point a, point b, point c){
//	long long ret = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
//	if (ret > 0)return 1;
//	else if (ret < 0)return -1;
//	else
//		return 0;
//}
//
//void swp(point *a, point *b){
//	point c = *a;
//	*a = *b;
//	*b = c;
//}
//
//int max(int a, int b){ return a < b ? b : a; }
//int min(int a, int b){ return a < b ? a : b; }
//
//int SMET(point X, point L, point L2){ // edge point on Rectangle
//
//	int my = L.y < L2.y ? L.y : L2.y;
//	int My = L.y > L2.y ? L.y : L2.y;
//	if (L.x <= X.x && X.x <= L2.x){
//		if (my <= X.y && X.y <= My){
//			if (!CCW(X, L, L2))return 1;
//		}
//	}
//
//	return 0;
//}
//
//int MEET(point R, point R2, point L, point L2){
//	int al = CCW(R, R2, L);
//	int ar = CCW(R, R2, L2);
//	int bl = CCW(L, L2, R);
//	int br = CCW(L, L2, R2);
//
//	if (al * ar < 0){
//		if (bl * br < 0){
//			return 1; // meet one point
//		}
//	}
//
//	if (!al && !ar){
//		int my = min(L.y, L2.y);
//		int My = max(L.y, L2.y);
//		if (L.x <= R.x && R.x < L2.x)return 8;
//		else if (L.x < R.x && R.x <= L2.x)return 8;
//		else if (R.x <= L.x && L.x < R2.x)return 8;
//		else if (R.x < L.x && L.x <= R2.x)return 8;
//		else if (my <= R.y && R.y < My)return 8;
//		else if (my < R.y && R.y <= My)return 8;
//		else if (R.y <= my && my < R2.y)return 8;
//		else if (R.y < my && my <= R2.y)return 8;
//		else if (R2.x == L.x || R2.y == L.y)return 1; // meet one point
//	}
//	if (!bl && !br){
//		int my = min(L.y, L2.y);
//		int My = max(L.y, L2.y);
//		if (L.x <= R.x && R.x < L2.x)return 8;
//		else if (L.x < R.x && R.x <= L2.x)return 8;
//		else if (R.x <= L.x && L.x < R2.x)return 8;
//		else if (my <= R.y && R.y < My)return 8;
//		else if (R.y <= my && my <= R2.y)return 8;
//		else if (L2.x == R.x || R2.y == L.y)return 1; // meet one point
//	}
//
//	if (al*ar == 0){
//		if (R.x <= L.x && L.x <= R2.x){
//			if (R.y <= L.y && L.y <= R2.y){
//				return 1;
//			}
//		}
//		if (R.x <= L2.x && L2.x <= R2.x){
//			if (R.y <= L2.y && L2.y <= R2.y){
//				return 1;
//			}
//		}
////		return SMET(R, L, L2) + SMET(R2, L, L2);
//	}
//
//	if (bl*br == 0){
//		int mx = min(L.x, L2.x);
//		int Mx = max(L.x, L2.x);
//		int my = min(L.y, L2.y);
//		int My = max(L.y, L2.y);
//		if (mx <= R.x && R.x <= Mx){
//			if (my <= R.y && R.y <= My){
//				return 1;
//			}
//		}
//		if (mx <= R2.x && R2.x <= Mx){
//			if (my <= R2.y && R2.y <= My){
//				return 1;
//			}
//		}
////		return SMET(L, R, R2) + SMET(L2, R, R2);
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		point R[4];
//		scanf("%d %d %d %d", &R[0].x, &R[0].y, &R[3].x, &R[3].y);
//		R[1].x = R[3].x, R[1].y = R[0].y;
//		R[2].x = R[0].x, R[2].y = R[3].y;
//
//		/*
//			2 3
//			0 1
//		*/
//
//		point L[2];
//		scanf("%d %d %d %d", &L[0].x, &L[0].y, &L[1].x, &L[1].y);
//
//		if (L[0].x > L[1].x)swp(&L[0], &L[1]);
//		else if (L[0].x == L[1].x && L[0].y > L[1].y)swp(&L[0], &L[1]);
//
//		int ans = MEET(R[0], R[1], L[0], L[1]);
//		ans += MEET(R[0], R[2], L[0], L[1]);
//		ans += MEET(R[2], R[3], L[0], L[1]);
//		ans += MEET(R[1], R[3], L[0], L[1]);
//
//		ans -= SMET(R[0], L[0], L[1]);
//		ans -= SMET(R[1], L[0], L[1]);
//		ans -= SMET(R[2], L[0], L[1]);
//		ans -= SMET(R[3], L[0], L[1]);
//
//		if (ans > 4)ans = 4;
//
//		printf("%d\n", ans);
//	}
//}
//
///*
//1
//0 0 3 3
//-1 3 4 3
//
//
//1
//0 0 8 4
//-2 5 10 -1
//2
//
//1
//0 0 8 4
//0 2 3 4
//2
//
//1
//0 0 5 5
//5 0 6 0
//*/

#include <stdio.h>

class point{
public:
	int x, y;
};

int CCW(point a, point b, point c){
	long long ret = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
	if (ret > 0)return 1;
	else if (ret < 0)return -1;
	else
		return 0;
}

void swp(point *a, point *b){
	point c = *a;
	*a = *b;
	*b = c;
}

int max(int a, int b){ return a < b ? b : a; }
int min(int a, int b){ return a < b ? a : b; }

int MEET(point &C, point &C2, point &S, point &S2){ // count intersection points C-C2 & S-S2
	int a = CCW(C, C2, S);
	int a2 = CCW(C, C2, S2);
	int b = CCW(S, S2, C);
	int b2 = CCW(S, S2, C2);

	int smx = min(S.x, S2.x);
	int smy = min(S.y, S2.y);
	int sMx = max(S.x, S2.x);
	int sMy = max(S.y, S2.y);
	int cmx = min(C.x, C2.x);
	int cmy = min(C.y, C2.y);
	int cMx = max(C.x, C2.x);
	int cMy = max(C.y, C2.y);

	if (a*a2 < 0 && b*b2 < 0)return 1;
	else if (!a && !a2 && !b2 && !b){
		if (smx <= C.x && C.x < sMx)return 8; // S C S2 C2
		else if (smy <= C.y && C.y < sMy)return 8;
		else if (sMx == cmx && sMy == cmy)return 1;
		else if (cmx <= S.x && S.x < cMx)return 8; // C S C2 S2
		else if (cmy <= S.y && S.y < cMy)return 8;
		else if (cMx == smx && cMy == smy)return 1;
	}else{
		if (a*a2 <= 0 && b*b2 <= 0){
			if (smx <= C.x && C.x <= sMx){
				if (smy <= C.y && C.y <= sMy){
					return 1;
				}
			}
			if (smx <= C2.x && C2.x <= sMx){
				if (smy <= C2.y && C2.y <= sMy){
					return 1;
				}
			}
			if (cmx <= S.x && S.x <= cMx){
				if (cmy <= S.y && S.y <= cMy){
					return 1;
				}
			}
			if (cmx <= S2.x && S2.x <= cMx){
				if (cmy <= S2.y && S2.y <= cMy){
					return 1;
				}
			}
		}
	}

	return 0;
}

int ONEPOINT(point &X, point &S, point &S2){ // square's point & line segment ' s meet
	int my = min(S.y, S2.y);
	int My = max(S.y, S2.y);
	int mx = min(S.x, S2.x);
	int Mx = max(S.x, S2.x);
	if (mx <= X.x && X.x <= Mx){
		if (my <= X.y && X.y <= My){
			if (!CCW(X, S, S2))return 1;
		}
	}
	return 0;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--){
		point R[4];
		scanf("%d %d %d %d", &R[0].x, &R[0].y, &R[3].x, &R[3].y);
		R[1].x = R[3].x, R[1].y = R[0].y;
		R[2].x = R[0].x, R[2].y = R[3].y;

		/*
		2 3
		0 1
		*/

		point L[2];
		scanf("%d %d %d %d", &L[0].x, &L[0].y, &L[1].x, &L[1].y);

		if (L[0].x > L[1].x)swp(&L[0], &L[1]);
		else if (L[0].x == L[1].x && L[0].y > L[1].y)swp(&L[0], &L[1]);

		int ans = MEET(R[0], R[1], L[0], L[1]);
		ans += MEET(R[1], R[3], L[0], L[1]);
		ans += MEET(R[2], R[3], L[0], L[1]);
		ans += MEET(R[0], R[2], L[0], L[1]);

		ans -= ONEPOINT(R[0], L[0], L[1]);
		ans -= ONEPOINT(R[1], L[0], L[1]);
		ans -= ONEPOINT(R[2], L[0], L[1]);
		ans -= ONEPOINT(R[3], L[0], L[1]);

		if (ans > 4)ans = 4;
		printf("%d\n", ans);
	}
}

/*
1
0 0 3 3
-1 3 4 3


1
0 0 8 4
-2 5 10 -1
2

1
0 0 8 4
0 2 3 4
2

1
0 0 5 5
5 0 6 0

*/