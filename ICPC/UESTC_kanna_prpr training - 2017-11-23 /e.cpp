#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int T,n,m;
bool sig;
int a[100][100];
int main(){
	scanf("%d",&T);
	for (int x=1;x<=T;x++){
		scanf("%d %d",&n,&m);
		sig=0;
		printf("Case #%d: ",x);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				sig|=((a[i][1]==a[j][1])|(a[i][m]==a[j][m]));
		for (int i=1;i<=m;i++)
			for (int j=i+1;j<=m;j++)
				sig|=((a[1][i]==a[1][j])|(a[n][i]==a[n][j]));
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++){
				if (i!=1&&a[i-1][j]==a[i][j])sig=1;
				if (j!=1&&a[i][j]==a[i][j-1])sig=1;
			}
		sig?printf("Yes\n"):printf("No\n");
	}
	return 0;
}
