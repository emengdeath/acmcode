#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000
using namespace std;
int T;
int n;
int a[N];
bool bz[N];
int main(){
	freopen("scoreboard.in","r",stdin);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=0;i<26;i++)bz[i]=0;
		for (int i=1;i<=n;i++){
			char c;
			scanf(" %c",&c);
			bz[c-'A']=1;
		}
		int x=0;
		while (bz[x])x++;
		for (int i=0;i<13;i++){
			scanf("%d",&a[i]);
			if (!bz[i]&&a[i]>a[x])x=i;
		}
		printf("%c\n",x+'A');
	}
	return 0;
}
