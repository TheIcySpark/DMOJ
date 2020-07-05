#include<iostream>
using namespace std;
/// Appleby Contest '19 P5 - Matrix Operation
int N;
int matriz[1502][1502];
int memo[1502][1502];
int movimientos[4][2]= {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void Lectura(){
	cin>>N;
	for(int i=1;i<=N; i++){
		for(int j= 1; j<=N; j++){
			cin>>matriz[i][j];
		}
	}
}

void InicializarMemo(){
	for(int i=1; i<= N; i++){
		for(int j=1; j<=N; j++){
			memo[i][j]= -1;
		}
	}
}

bool RutaValida(int& i, int&j, int& valorAnterior){
	if(i<1 or j<1 or i>N or j>N or matriz[i][j]<= valorAnterior) return false;
	else return true;
}

int CaminoMasLargo(int i, int j, int valorAnterior){
	if(! RutaValida(i, j, valorAnterior)) return -1;
	if(memo[i][j]==-1){
		int mayor= -1;
		for(int k=0; k<4; k++){
			mayor= max(mayor, CaminoMasLargo(i+ movimientos[k][0], j+ movimientos[k][1], matriz[i][j]) +1);
		}
		memo[i][j]= mayor;
	}
	return memo[i][j];
}

int ObtenerCaminoMasLargo(){
	int mayor= -1;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			mayor=max(mayor, CaminoMasLargo(i, j, 0));
		}
	}
	return mayor;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Lectura();
	InicializarMemo();
	cout<<ObtenerCaminoMasLargo()<<'\n';

	return 0;
}
/**
3
9 8 4
7 2 3
6 1 5
**/