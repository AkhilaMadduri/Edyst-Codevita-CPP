#include<queue>
#include<iostream>
using namespace std;
int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1}; 
int n, m;
char ar[1001][1001];
int dis[1001][1001];
int pos[1001][1001];
void go(int X, int Y ){
	queue<int> x, y;
	x.push(X);
	y.push(Y);
	dis[X][Y] = 0;
	pos[X][Y] = -1;
	while( !x.empty() ){
		int XX = x.front(); x.pop();
		int YY = y.front(); y.pop();
		for( int i = 0; i < 8; i++ ){
			int xx = XX + dx[i];
			int yy = YY + dy[i];
			if( xx < 0 || yy < 0 || xx >= n || yy >= m ){}
			else if( ar[xx][yy] != 'w'){
				if( dis[xx][yy] > dis[XX][YY]+1 ){
					dis[xx][yy] = dis[XX][YY] + 1;
					x.push(xx);
					y.push(yy);
					pos[xx][yy] = i;
				}
			}
		}
	}
}
void print(int x, int y, int add){
	char a[n][m];
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < m; j++ ){
			a[i][j] = '-';
		}
	}
	while( ar[x][y] != 'd' ){
		a[x][y] = 'a' + add;
		int i = pos[x][y];
		x -= dx[i];
		y -= dy[i];
	}
	a[x][y] = 'd';
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < m; j++ ){
			if( ar[i][j] == 'w' )a[i][j] = 'w';
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int main(){
	int x, y;
	cin >> n >> m;
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < m; j++ ){
			cin >> ar[i][j];
			dis[i][j] = 100000;
			if( ar[i][j] == 'd' )x = i, y = j;
		}
	}
	go(x, y);
    int cnt = 0;
    for( int i = 0; i < n; i++ ){
		for( int j = 0; j < m; j++ ){
			if( ar[i][j] == 's' ){
				print(i, j, cnt++);
				cout << endl;
			}
		}
	}
}
