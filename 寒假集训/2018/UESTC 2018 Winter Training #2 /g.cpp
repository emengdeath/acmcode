#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 200
using namespace std;
int f[N][N][3];
int n,m,ans;
int main(){
	scanf("%d %d",&n,&m);
	f[0][0][0]=1;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for (int j=0;j<i;j++)
			for (int k=0;k<3;k++)
				if (f[i-1][j][k]){
					int y=m;
					int z=j;
					while (z)z--,y=y*2/3;
					f[i][j+1][0]=max(f[i][j+1][0],min(y,x)+f[i-1][j][k]);
					if (k+1==2)
						f[i][0][2]=max(f[i][0][2],f[i-1][j][k]);
					else
						f[i][max(j-1,0)][k+1]=max(f[i][max(j-1,0)][k+1],f[i-1][j][k]);
				}
	}
	for (int i=0;i<=n;i++)
		for (int j=0;j<3;j++)
		ans=max(ans,f[n][i][j]);
	printf("%d\n",ans-1);
	return 0;
}
