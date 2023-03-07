#include <iostream>
#include <fstream>
#include <queue>
#define INF 9999
using namespace std;
ifstream fin("graf.txt");

int grf[100][100],n;
int dst[100],pi[100];
bool ok[100];
queue<int>coada;

void bfs(int nod_start) {
	ok[nod_start] = 1;
	coada.push(nod_start);
	int i, j;
	for (i = 1; i <= n; ++i) {
		dst[i] = INF;
		pi[i] = -1;
	}
	dst[nod_start] = 0;
	pi[nod_start] = 0;
	while (!coada.empty()) {
		int nod_current = coada.front();
		coada.pop();
		for(i=1;i<=n;++i)
			if (!ok[i] && grf[nod_current][i]) {
				ok[i] = 1;
				dst[i] = dst[nod_current] + 1;
				pi[i] = nod_current;
				coada.push(i);
			}
	}
}

int main() {
	int x,y,i, j,nod_start,nod_final;
	fin >> n;
	while (fin >> x >> y) {
		grf[x][y] = 1;
	}
	cout << "Nodul de inceput va fi: ";
	cin >> nod_start;
	bfs(nod_start);
	/*for (i = 1; i <= n; ++i)
		cout << dst[i] << ' ';
	cout << '\n';
	for (i = 1; i <= n; ++i)
		cout << pi[i] << ' ';*/
	cout << "Nodul de final va fi: ";
	cin >> nod_final;
	if (dst[nod_final] == INF) {
		cout << "NU se poate";
	}
	else {
		cout << "Lantul va fi: ";
		cout << nod_final<<' ';
		while (pi[nod_final] != 0) {
			nod_final = pi[nod_final];
			cout << nod_final << " ";
		}
	}
	return 0;
}