#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *z , int X , int Y){
    cout << fixed << setprecision(2);
    for(int i = 0; i < X*Y; i++){
        cout << z[i];
        if((i+1) % Y == 0) cout << endl;
        else cout << " ";
    }
}

void randData(double *z , int X , int Y){
    for(int i = 0; i < X*Y; i++){
        z[i] = (rand() % 101 / 100.0);
    }
}

void findRowSum(const double *a , double *b , int c , int d){
	for(int i = 0 ; i < c ; i++){
		double j = 0 ;
		for(int k = 0 ; k < d ; k++){
			j += *((a+k) + (d*i)) ;
		}
		b[i] = j ;
	}
}

void findColSum(const double *a , double *b , int c , int d){
	int i = 0 , j = 0 ;
	b[j] = 0 ;

	for(int s = 0 ; s < d ; s++){
		i = s ;
		for(int t = 0 ; t < c ; t++){
		b[j] += a[i] ;
		i += d ;
	}

	j++ ;
	b[j] = 0 ;
	}
}