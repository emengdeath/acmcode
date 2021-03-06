#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100
using namespace std;
char s[N][N];
int n,m,sum,T;
int ans[4];
void update(int x1,int y1,int z1,int u1){	
	if (y1>u1){
		swap(x1,z1);
		swap(y1,u1);
	}
	if (y1==u1&&x1>z1){
		swap(x1,z1);
		swap(y1,u1);	
	}
	if (!ans[0]||(ans[0]>x1||(ans[0]==x1&&(ans[1]>y1||(ans[1]==y1&&(ans[2]>z1||(ans[2]==z1&&ans[3]>u1))))))){
		ans[0]=x1,ans[1]=y1,ans[2]=z1,ans[3]=u1;
	}
}
long long did(long long x,long long y,long long xx,long long yy){
	return x*yy-xx*y;
}
long long cross(int x,int y,int xx,int yy,int xxx,int yyy){
	return did(xx-x,yy-y,xxx-x,yyy-y);
}
int main(){
	freopen("d.in","r",stdin);
	scanf("%d",&T);
	while (T--){
		scanf("%d %d",&n,&m);
		ans[0]=ans[1]=ans[2]=ans[3]=0;
		sum=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				scanf(" %c",&s[i][j]),sum+=(s[i][j]=='.');
		for (int i=1;i<n;i++){
			int sum1=0;
			for (int j=1;j<=i;j++){
				int j1=i-j+i+1;
				if (j1<=n)
				for (int k=1;k<=m;k++){
					if (s[j][k]!=s[j1][k])sum1++;
					else
						sum1=sum+1;
				}
			}
			if (sum1==sum){
				update(i,1,i,m);
				break;
			}
		}
		for (int i=1;i<m;i++){
			int sum1=0;
			for (int j=1;j<=i;j++){
				int j1=i-j+i+1;
				if (j1<=m)
				for (int k=1;k<=n;k++)
					if (s[k][j]!=s[k][j1])sum1++;
					else
						sum1=sum+1;
			}
			if (sum1==sum){
				update(1,i,n,i);
				break;
			}
		}
		for (int i=1;i<=n+m-1;i++){
			int sum1=0;
			int x=min(i,n),y=max(1,i-n+1),x1,y1;
			for (int j=1;j;j++)
				if (x-j==0||y+j>m){
					x1=x-j+1;
					y1=y+j-1;
					break;
				}
			for (int j=1;j<=n;j++)
				for (int k=1;k<=m;k++){
					if (cross(x,y,x1,y1,j,k)<=0)continue;
					int j1=y1+(x1-j),k2=x1-(k-y1);
					if (1<=j1&&j1<=n&&1<=k2&&k2<=m){
					if (s[j][k]!=s[j1][k2])sum1++;
					else
						sum1=sum+1;
					}
				}
			if (sum1==sum){
				update(x,y,x1,y1);
			}
		}
		for (int i=1;i<=n+m-1;i++){
			int sum1=0;
			int x=n-min(i,n)+1,y=max(1,i-n+1),x1,y1;
			for (int j=1;j;j++)
				if (x+j>n||y+j>m){
					x1=x+j-1;
					y1=y+j-1;
					break;
				}
			for (int j=1;j<=n;j++)
				for (int k=1;k<=m;k++){
					if (cross(x,y,x1,y1,j,k)<=0)continue;
					int j1=x1+(k-y1),k2=y1+(j-x1);
					if (1<=j1&&j1<=n&&1<=k2&&k2<=m){
					if (s[j][k]!=s[j1][k2])sum1++;
					else
						sum1=sum+1;
					}
				}
			if (sum1==sum){
				update(x,y,x1,y1);
			}
		}
		printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
	}
	return 0;
}
