#include <stdio.h>
#include <stdlib.h>

int imod, n;

class SquareMatrix{
public:
    long long e[35][35];
    SquareMatrix(){
        for(register int i=0; i<35; i++){
            for(register int j=0; j<35; j++){
                e[i][j] = 0;
            }
        }
    }
    
    SquareMatrix(const SquareMatrix& A){ // fast copy
        for(register int i=0; i<n; i++)for(register int j=0; j<n; j++){
            e[i][j] = A.e[i][j];
        }
    }
    
    SquareMatrix& operator=(const SquareMatrix& A){
        for(register int i=0; i<n; i++){
            for(register int j=0; j<n; j++){
                e[i][j] = A.e[i][j];
            }
        }
        return *this;
    }
    
    SquareMatrix operator+(const SquareMatrix &A)const{
		SquareMatrix ret;
		for (register int i=0; i<n; i++)for(register int j=0; j<n; j++)ret.e[i][j] = (e[i][j] + A.e[i][j]) % imod;
		return ret;
	}

    SquareMatrix& operator+=(const SquareMatrix &A){
        for (register int i=0; i<n; i++)for(register int j=0; j<n; j++){
            e[i][j] += A.e[i][j];
            e[i][j] %= imod;
        }
		return *this;
	}

    SquareMatrix operator*(const SquareMatrix &A)const{
        SquareMatrix ret;
        for(register int i=0; i<n; i++){
            for(register int j=0; j<n; j++){
                for(register int k=0; k<n; k++){
                    ret.e[i][j] += (e[i][k] * A.e[k][j]) % imod;
                    ret.e[i][j] %= imod;
                }
            }
        }
        return ret;
    }
};

SquareMatrix I, apow[22], base;

SquareMatrix matrixPower(int p){ 
    // calculate a^p
    SquareMatrix ret = I;
    for(register int i=0; (1<<i) <= p; i++){
        if(p&(1<<i))ret = ret * apow[i];
    }return ret;
}

SquareMatrix calc(int r){
    if(r == 1)return base;
    else{
        SquareMatrix ans;
        SquareMatrix tmp = I;
        tmp += matrixPower(r>>1);
        ans = calc(r>>1) * tmp;
        if(r&1){
            ans += matrixPower(r);
        }
        return ans;
    }
}

char str[38];

int main(){
    
    for(register int i=0; i<35; i++)I.e[i][i] = 1;
    
    int r;
    scanf("%d %d %d", &n, &r, &imod);

    for(register int i=0; i<n; i++){
        scanf("%s", str);
        for(register int j=0; j<n; j++){
            base.e[i][j] = (str[j] == 'Y');
        }
    }
    r--;

    for(register int i=0; (1<<i) <= r; i++){
        if(i == 0)apow[i] = base;
        else
            apow[i] = apow[i-1] * apow[i-1];
    }
            
    SquareMatrix ans = calc(r);
    int ret = 0;
    for(register int i=0; i<n; i++)ret = (ret + ans.e[i][i]) % imod;
    printf("%d\n", ret);

}