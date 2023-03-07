#include <iostream>
#include <fstream>
#define INF 9999

using namespace std;
ifstream fin("graf.txt");

int grf[100][100], n,inchidere[100][100];

int main() {
	fin >> n;
	int x,y,i, j,k;
	for (i = 0; i <= n; ++i)
		for (j = 0; j <= n; ++j)
			if(i!=j)inchidere[i][j] = INF;
	while (fin >> x >> y) {
		grf[x][y] = 1;
		inchidere[x][y] = 1;
	}
	for (k = 0; k <= n; k++) {
		for (i = 0; i <= n; i++) {
			for (j = 0; j <= n; j++) {
				if (inchidere[i][j] > (inchidere[i][k] + inchidere[k][j])
					&& (inchidere[k][j] != INF
						&& inchidere[i][k] != INF))
					inchidere[i][j] = inchidere[i][k] + inchidere[k][j];
			}
		}
	}
	for (i = 0; i <= n; ++i)
	{
		for (j = 0; j <= n; ++j)
			if (inchidere[i][j] == INF)cout << 0 << ' ';
			else cout << 1 << ' ';
		cout << '\n';
	}
	cin >> n;
}