#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 100
#include<cstring>
using namespace std;
char map[N][N];
int a[N];
int n;
bool check(){
	bool b[26];
	for (int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for (int j=1;j<=n;j++){
			if (b[map[i][j]])return 0;
			b[map[i][j]]=1;
		}
	}
	for (int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for (int j=1;j<=n;j++){
			if (b[map[j][i]])return 0;
			b[map[j][i]]=1;
		}
	}
	return 1;
}
int main(){
	while (scanf("%d",&n)!=EOF){
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				scanf(" %c",&map[i][j]),a[map[i][j]-='A']++;
		int x,y;
		for (int i=0;i<26;i++){
			if (a[i]==1||a[i]>n)x=i;
			if (a[i]==n-1)y=i;
		}
		bool sig=0;
		int ansx,ansy;
		for (int i=1;i<=n&&!sig;i++)
			for (int j=1;j<=n&&!sig;j++)
				if (map[i][j]==x){
					map[i][j]=y;
					if (check()){
						ansx=i,ansy=j;
						sig=1;
					}
					map[i][j]=x;
				}
		printf("%d %d %c\n",ansx,ansy,y+'A');
	}
	return 0;
}
