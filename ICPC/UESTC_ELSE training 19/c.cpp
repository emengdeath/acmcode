#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int T;
int x,y,k;
bool check(int s){
	int v=x*s*11;
	return (k-s)*(11*y-9*x)<=v;
}
int main(){
	scanf("%d",&T);
	for (int sig=1;sig<=T;sig++){
		printf("Case #%d: ",sig);
		scanf("%d %d %d",&x,&y,&k);
		if (y<x){
			printf("%d\n",k);
			continue;
		}
		int l=0,r=k,s=k,mid;
		while (l<=r)
			if (check(mid=(l+r)/2))s=min(s,mid),r=mid-1;
			else
				l=mid+1;
		printf("%d\n",k-s);	
	}
	return 0;
}
