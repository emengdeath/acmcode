#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 10000000
using namespace std;
int a[N];
int l,r,n,T,l1,r1;
bool rev;
char s[10];
void output(int x){
	printf("%d\n",x&1);
}
int main(){
	scanf("%d",&T);
	for (int sig=1;sig<=T;sig++){
		printf("Case #%d:\n",sig);
		scanf("%d",&n);
		l=1,r=0;
		l1=5000000,r1=4999999;
		rev=0;
		while (n--){
			scanf(" %s",s);
			if (s[0]=='P'&&s[1]=='U'){
				int x;
				scanf("%d",&x);
				if (!rev){
					r++;
					if (!x){
						r1++;
						a[r1]=r;
					}
				}else{
					l--;
					if (!x){
						l1--;
						a[l1]=l;
					}
				}
			}else
			if (s[0]=='P'){
				if (l>r)continue;
				if (!rev){
					r--;
					if (a[r1]>r)r1--;
				}else{
					l++;
					if (a[l1]<l)l1++;
				}
			}else
			if (s[0]=='R')rev^=1;
			else{
				if (l>r){
					printf("Invalid.\n");
					continue;
				}
				if (!rev){
					if (l1>r1){
						output(r-l+1);
					}else{
						if (r==a[l1])output(a[l1]-l);
						else
							output(a[l1]-l+1);
					}
				}else{
					if (l1>r1){
						output(r-l+1);
					}else{
						if (l==a[r1])output(r-a[r1]);
						else
							output(r-a[r1]+1);
					}
				}
			}
		}
	}
	return 0;
}
