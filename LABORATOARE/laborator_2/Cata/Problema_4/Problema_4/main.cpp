#include <iostream>
#include <fstream>
#include <queue>
#define INF 9999

using namespace std;
ifstream fin("graf.txt");

queue<int>coada;
int grf[100][100], n, dst[100];
bool ok[100];

void bfs(int nod_sursa) {
	ok[nod_sursa] = 1;
	int i;
	for (i = 1; i <= n; ++i)
		dst[i] = INF;
	coada.push(nod_sursa);
	dst[nod_sursa] = 0;
	while (!coada.empty()) {
		int nod_current = coada.front();
		ok[nod_current] = 1;
		coada.pop();
		for(i=1;i<=n;++i)
			if (!ok[i] && grf[nod_current][i]){ 
				ok[i] = 1;
				dst[i] = dst[nod_current] + 1;
				coada.push(i);
			}
	}
}

int main() {
	fin >> n;
	int x,y,i, j,nod_sursa;
	while (fin >> x >> y) {
		grf[x][y] = 1;
	 }
	cout << "Nodul sursa este: ";
	cin >> nod_sursa;
	bfs(nod_sursa);
	cout << "Distantele vor fi: ";
	for (i = 1; i <= n; ++i)
		if (dst[i] != INF)cout << dst[i] << ' ';
		else cout << "- ";
	cin >> n;
}