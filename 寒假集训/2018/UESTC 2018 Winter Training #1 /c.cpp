#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 1000
#define M 100
#include <cstring>
using namespace std;
struct node{
	int x, y;
}a[N];
int f[M+1][M+1];
int n, T;
bool cmp(const node&a, const node&b){
	return a.x < b.x || (a.x == b.x && a.y > b.y);
}
int read(){
	int x, y;
	scanf("%d.%d", &x, &y);
	return x * 10 + y;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i<= n; i++){
			a[i].x = read();
			a[i].y = read();
		}
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++){
			for (int x = 0; x < a[i].x; x++)
				for (int y = a[i].y + 1; y <= M; y++)
					f[a[i].x][a[i].y] = max(f[a[i].x][a[i].y],f[x][y] + 1);
			f[a[i].x][a[i].y] = max(f[a[i].x][a[i].y], 1);
		}
		int ans = 0;
		for (int i = 0; i <= M; i++)
			for (int j = 0; j <= M; j++)
				ans = max(ans, f[i][j]);
		printf("%d\n", ans);
	}
	return 0;
}
