#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	string s;
	cin>>n>>k;
	cin>>s;
	int l=0;
	while (k){
		while (l+1<s.size()&&(s[l]!='4'||s[l+1]!='7'))l++;
		if (l+1==s.size())break;
		if ((l+1)&1){
			if (l+2<s.size()&&s[l+2]=='7'){
				if (k&1)s[l]=s[l+1]='4';	
				k=0;
			}else{
				s[l]=s[l+1]='4';
				k--;
			}
		}else{
			if (l&&s[l-1]=='4'){
				if (k&1)s[l]=s[l+1]='7';
				k=0;
			}else{
				s[l]=s[l+1]='7';
				k--;
				if (l)l--;
			}
		}
	}
	cout<<s;
	return 0;
}
