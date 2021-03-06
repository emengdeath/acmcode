#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 10000007
#include<cstring>
using namespace std;
int n,m,x,y,sig,calc;
char s[10000];
int link[10001][3],to[N+1];
bool f[1000][1000],f1[1000][1000];
int turn(char x){
	return 'a'<=x&&x<='z'?x-'a'+1:x-'A'+27;
}
int getid(char*s){
	int len=strlen(s);
	int v=0;
	for (int i=0;i<len;i++)v=((long long)v*53+turn(s[i]))%N;
	if (!to[v+1])to[v+1]=++calc;
	return to[v+1];
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		link[i][0]=getid(s);
		scanf("%s",s);
		if (s[0]=='i')link[i][1]=1;
		scanf("%s",s);
		link[i][2]=getid(s);
	}
	for (int i=1;i<=n;i++)
		if (!link[i][1]){
			f1[link[i][0]][link[i][2]]=1;
		}
	for (int i=1;i<=n;i++)
		if (link[i][1]){
			f[link[i][0]][link[i][2]]=1;
			f1[link[i][0]][link[i][2]]=1;
		}
	for (int i=1;i<=calc;i++)
		for (int j=1;j<=calc;j++)
			if (i!=j&&f[j][i])
				for (int k=1;k<=calc;k++)
					if (i!=k&&k!=j&&f[i][k])
						f[j][k]=1;
	for (int i=1;i<=calc;i++)
		for (int j=1;j<=calc;j++)
			if (i!=j&&f1[j][i])
				for (int k=1;k<=calc;k++)
					if (i!=k&&k!=j&&f1[i][k])
						f1[j][k]=1;
	for (int i=1;i<=m;i++){
		printf("Query %d: ",i);
		scanf("%s",s);
		x=getid(s);
		scanf("%s",s);
		if (s[0]=='i')sig=1;
		else
			sig=0;
		scanf("%s",s);
		y=getid(s);
		if (sig){
			f[x][y]||x==y?printf("true\n"):printf("false\n");
		}else
			(!f[x][y]&&f1[x][y])?printf("true\n"):printf("false\n");
	}
	return 0;
}
