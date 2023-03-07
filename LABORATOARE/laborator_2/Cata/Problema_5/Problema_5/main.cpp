#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("graf.txt");

int n;
bool ok[100];

void DFS_VISIT(int grf[100][100], int u) {
	ok[u] = 1;
	for(int i=1;i<=n;i++)
		if (!ok[i] && grf[u][i]==1) {
			DFS_VISIT(grf, i);
		}
}
int main() {
	int grf[100][100];
	int i,j,x,y,u;
	fin >> n;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			grf[i][j] = 0;
	while (fin >> x >> y) {
		grf[x][y] = 1;
	}
	cout << "Nodul de inceput va fi: ";
	cin >> u;
	DFS_VISIT(grf, u);
	cout << "Noduriile care se pot vizita sunt: ";
	for (i = 1; i <= n; ++i)
		if (ok[i] && i!=u)cout << i << ' ';
}