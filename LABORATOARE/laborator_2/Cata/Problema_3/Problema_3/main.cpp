#include <iostream>
#include <fstream>
#include <queue>
#include <string.h>
#define INF 9999

using namespace std;
ifstream fin("input.txt");

queue<pair<int, int>>coada;
char matrice[100][100];
int grf[100][100], distante[100][100], n,m=41, ok[100][100], i_inceput, j_inceput, i_final, j_final;
int di[] = { 1,-1,0,0 };
int dj[] = { 0,0,1,-1 };
bool valid(int i, int j) {
	if (i < 0 || j < 0 || i >= m || j >= m || distante[i][j] == -1 || ok[i][j] == 1)
		return false;
	return true;
}
void bfs() {
	int i, j, k;
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			if (matrice[i][j] == '1')distante[i][j] = -1;
			else distante[i][j] = INF;
	distante[i_inceput][j_inceput] = 0;
	ok[i_inceput][j_inceput] = 1;
	coada.push({ i_inceput,j_inceput });
	while (!coada.empty()) {
		int i_current = coada.front().first, j_current = coada.front().second;
		ok[i_current][j_current] = 1;
		coada.pop();
		for (k = 0; k <= 3; ++k)
		{
			int noul_i = i_current + di[k];
			int noul_j = j_current + dj[k];
			if (valid(noul_i, noul_j)) {
				distante[noul_i][noul_j] = distante[i_current][j_current] + 1;
				ok[noul_i][noul_j] = 1;
				coada.push({ noul_i,noul_j });
			}
		}
	}
}
int main() {
	int i, j, m;
	n = 22;
	for (i = 0; i < n - 1; ++i)
	{
		fin.getline(matrice[i], 49);
	}
	--n;
	for (i = 0; i < n; ++i)
	{
		m = strlen(matrice[i]);
		for (j = 0; j < m; ++j)
			if (matrice[i][j] == 'S') {
				i_inceput = i;
				j_inceput = j;
			}
			else if (matrice[i][j] == 'F') {
				i_final = i;
				j_final = j;
			}
	}
	//0 22
	/*cout << i_inceput << '\n';
	cout << j_inceput << '\n';*/
	
	bfs();
	cout << i_final << ' ' << j_final << '\n';
	while (distante[i_final][j_final] != 0) {
		for (int k = 0; k <= 3; ++k)
		{
			int noul_i = i_final + di[k];
			int noul_j = j_final + dj[k];
			if (distante[noul_i][noul_j]==distante[i_final][j_final]-1 && noul_i>=0 && noul_j>=0 && noul_i<m && noul_j<m) {
				i_final = noul_i;
				j_final = noul_j;
				break;
			}
		}
		cout << i_final<<' ' << j_final << '\n';
	}
	cin >> n;
}