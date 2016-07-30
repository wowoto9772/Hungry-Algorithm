#include <stdio.h>

class ele{
public:
	int c;
	long long i, j; // j-th number in i-th number
}L[22], R[22], I[22];

int what[3][3] = { { 0, 2, 1 }, { 1, 0, 0 }, {1, 2, 1} };
int add[3][3] = { { 1, 1, 1 }, { 2, 1, 0 }, {0, 2, 1 } };
long long C[3];

int main(){
	int F, l, r, N;
	scanf("%d %d %d %d", &F, &l, &r, &N);

	L[0].c = R[0].c = F-1, L[N].i = l, R[N].i = r;
	C[L[0].c] = 1;

	for (int i = N - 1; i>=0; i--){
		L[i].i = L[i + 1].i / 3, L[i].j = L[i + 1].i % 3;
		R[i].i = R[i + 1].i / 3, R[i].j = R[i + 1].i % 3;
	}

	for (int i = 0; i < N; i++){
		//printf("%d %d %d %d\n", L[i].i, L[i].j, R[i].i, R[i].j);
		long long tC[3] = { 0 };
		for (int k = 0; k < 3; k++){
			for (int j = 0; j < 3; j++)tC[j] += C[k] * add[k][j];
		}
		for (int k = 0; k < L[i].j; k++)tC[what[L[i].c][k]]--;
		for (int k = R[i].j+1; k < 3; k++)tC[what[R[i].c][k]]--;

		L[i + 1].c = what[L[i].c][L[i].j];
		R[i + 1].c = what[R[i].c][R[i].j];
		for (int k = 0; k < 3; k++)C[k] = tC[k];
	}

	printf("%lld %lld %lld\n", C[0], C[1], C[2]);
} // 1 2 6 2

// 1 1 1 2 가 안나옴 엎고 다시 하기. 정리해서

/*
	1
	132
	132232211

	0,0
	0,2 2,0
	2 6


	2
	232
	232211232
*/