#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 200
#include<cstring>
using namespace std;
char a[N][N],b[N][N];
int n,x,y,sig;
int c[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool check(int x,int y){
	return x&&y&&x<=n&&y<=n;
}
bool check1(int x,int y){
	x+=c[sig][0],y+=c[sig][1];
	if (!check(x,y))return 0;
	return !b[x][y];
}
void update(int x1,int y1){
	if (!check(x1,y1))return;
	while (!check1(x,y))sig=(sig+1)%4;
	x+=c[sig][0],y+=c[sig][1];
	b[x][y]=a[x1][y1];
}
int main(){
	while (scanf("%d",&n)!=EOF){
		memset(b,0,sizeof(b));
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				scanf(" %c",&a[i][j]);
		x=1,y=0;
		sig=0;
		for (int i=1;i<=n+n-1;i++){
			if (i&1)
				for (int j=1;j<=i;j++)
					update(i-j+1,j);
			else
				for (int j=1;j<=i;j++)
					update(j,i-j+1);
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++)
				printf("%c",b[i][j]);
			printf("\n");
		}
	}
	return 0;
}
