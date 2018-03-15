#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
long long f[34][2][2][33],help[33];
long long L,R,c;
int k;
int main(){
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
	int T;
	scanf("%d",&T);
	help[1]=1;
	for (int i=2;i<=32;i++)help[i]=help[i-1]*2;
	for (int sig=1;sig<=T;sig++){
		printf("Case %d: ",sig);
		scanf("%lld %lld %lld %d",&L,&R,&c,&k);
		memset(f,0,sizeof(f));
		f[33][1][1][0]=1;
		for (int i=33;i>1;i--){
			int x=L/help[i-1]%2;
			int y=R/help[i-1]%2;
			int v=c/help[i-1]%2;
			for (int j=0;j<2;j++)
				for (int k=0;k<2;k++)
					for (int sum=0;sum<=32;sum++)
						if (f[i][j][k][sum]){
							int l=0,r=1;
							if (j==1)l=x;
							if (k==1)r=y;
							for (int z=l;z<=r;z++)
								if ((v&z)==z)
									f[i-1][j&&z==x][k&&z==y][sum+z]+=f[i][j][k][sum];
						}
		}
		long long ans1=0;
		for (int sum=0;sum<=32;sum++)
			if (abs(sum-(32-sum))<=k)
				ans1+=f[1][0][0][sum]+f[1][0][1][sum]+f[1][1][0][sum]+f[1][1][1][sum];
		memset(f,0,sizeof(f));
		f[33][1][1][0]=1;
		for (int i=33;i>1;i--){
			int x=L/help[i-1]%2;
			int y=R/help[i-1]%2;
			int v=c/help[i-1]%2;
			for (int j=0;j<2;j++)
				for (int k=0;k<2;k++)
					for (int sum=0;sum<=32;sum++)
						if (f[i][j][k][sum]){
							int l=0,r=1;
							if (j==1)l=x;
							if (k==1)r=y;
							for (int z=l;z<=r;z++)
								if ((v^z)==z)
									f[i-1][j&&z==x][k&&z==y][sum+z]+=f[i][j][k][sum];
						}
		}
		long long ans2=0;
		for (int sum=0;sum<=32;sum++)
			if (abs(sum-(32-sum))<=k)
				ans2+=f[1][0][0][sum]+f[1][0][1][sum]+f[1][1][0][sum]+f[1][1][1][sum];
		memset(f,0,sizeof(f));
		f[33][1][1][0]=1;
		for (int i=33;i>1;i--){
			int x=L/help[i-1]%2;
			int y=R/help[i-1]%2;
			int v=c/help[i-1]%2;
			for (int j=0;j<2;j++)
				for (int k=0;k<2;k++)
					for (int sum=0;sum<=32;sum++)
						if (f[i][j][k][sum]){
							int l=0,r=1;
							if (j==1)l=x;
							if (k==1)r=y;
							for (int z=l;z<=r;z++)
								if ((v|z)==z)
									f[i-1][j&&z==x][k&&z==y][sum+z]+=f[i][j][k][sum];
						}
		}
		long long ans3=0;
		for (int sum=0;sum<=32;sum++)
			if (abs(sum-(32-sum))<=k)
				ans3+=f[1][0][0][sum]+f[1][0][1][sum]+f[1][1][0][sum]+f[1][1][1][sum];
		printf("%lld %lld %lld\n",ans1,ans2,ans3);
	}
	return 0;
}
