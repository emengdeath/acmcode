#include<bits/stdc++.h>
#define next Next 
#define min(x,y) (x<y?x:y)
using namespace std;
const long long MOD=55629113;
const int N=2e5+1;
int g[MOD];
string s;
int ans[N],next[N];
int help[N],f[N];
int n;
struct node{
    int bz,k,v;
    string s;
}a[N];
struct IO{
    private:
    static const int MT = 1024*1024;
    char BUFF[MT];
    char tmp[MT];
    int IO_PTR,IO_SZ;
    public:
    IO(){
        begin();
    }
    bool begin()
    {
        IO_PTR=0;
        IO_SZ=fread(BUFF,1,MT,stdin);
        if(IO_SZ==0)    return false;
        return true;
    }
    bool readstring(string &str)
    {
        int cnt=0;
        while(true)
        {
            while(IO_PTR==IO_SZ)    if(!begin())    return false;
            if(BUFF[IO_PTR]==' '||BUFF[IO_PTR]=='\n'||BUFF[IO_PTR]=='\r')
                IO_PTR++;
            else break;
        }
        while(true)
        {
            while(IO_PTR<IO_SZ&&BUFF[IO_PTR]!=' '&&BUFF[IO_PTR]!='\n'&&BUFF[IO_PTR]!='\r')
                tmp[cnt++]=BUFF[IO_PTR++];
            if(IO_PTR==IO_SZ)
            {
                if(!begin())
                    break;
            }else break;

        }
        tmp[cnt]=0;
        str=string(tmp);
        return true;
    }
    bool readlonglong(long long &ans)
    {
        char c;
        while(true)
        {
            while(IO_PTR==IO_SZ)    if(!begin())    return false;
            c=BUFF[IO_PTR];
            if((c>'9'||c<'0')&&(c!='-'))
                IO_PTR++;
            else break;
        }
        long long f=1;
        if(c=='-')  f=-1;
        ans=0;
        while(true)
        {
            while(IO_PTR<IO_SZ&&(c=BUFF[IO_PTR]))
            {
                if(c>'9'||c<'0')    break;
                ans=ans*10+c-'0';
                IO_PTR++;
            }
            if(IO_PTR==IO_SZ)
            {
                if(!begin())    break;
            }else break;
        }
        ans=f*ans;
        return true;
    }
    bool readint(int &ans)
    {
        char c;
        while(true)
        {
            while(IO_PTR==IO_SZ)    if(!begin())    return false;
            c=BUFF[IO_PTR];
            if((c>'9'||c<'0')&&(c!='-'))
                IO_PTR++;
            else break;
        }
        int f=1;
        if(c=='-')  f=-1;
        ans=0;
        while(true)
        {
            while(IO_PTR<IO_SZ&&(c=BUFF[IO_PTR]))
            {
                if(c>'9'||c<'0')    break;
                ans=ans*10+c-'0';
                IO_PTR++;
            }
            if(IO_PTR==IO_SZ)
            {
                if(!begin())    break;
            }else break;
        }
        ans=f*ans;
        return true;
    }
}io;
inline int get(int l,int r){
    return (f[r]-(long long)f[l]*help[r-l]%MOD+MOD)%MOD;
}
bool cmp(const node&a,const node&b){
    return a.s.size()<b.s.size();
}

void work(int l,int r){
    int len=a[l].s.size();
    int tot=0;
    for (int i=l;i<=r;i++)g[a[i].v]=0;
    int x,y;
    for (int i=1;i+len-1<=s.size();i++){
        x=i;
        y=get(i-1,i+len-1);
       /* next[i]=g[y];  
        g[y]=i;*/
        swap(next[i],x);
    }
    for (int i=l;i<=r;i++){
        x=g[a[i].v],y=x;
        for (int j=2;j<=a[i].k&&x;j++)x=next[x];
        if (!x)ans[a[i].bz]=-1;
        else{
            ans[a[i].bz]=s.size();
            while (x){
                ans[a[i].bz]=min(ans[a[i].bz],(y+len-1)-x+1),x=next[x];
                y=next[y];
            }
        }
    }
}
int did(string&a){
    long long v=0;
    for (int i=0;i<a.size();i++)v=(v*26+a[i]-'a')%MOD;
    return v;
}
int main(){
   // freopen("d.in","r",stdin);
   // ios::sync_with_stdio(false); 
    io.readstring(s);
    help[0]=1;
    for (int i=1;i<=s.size();i++)
        f[i]=(f[i-1]*26+s[i-1]-'a')%MOD,help[i]=help[i-1]*26%MOD;
    io.readint(n);
    for (int i=1;i<=n;i++){
        io.readint(a[i].k);
        io.readstring(a[i].s);
        a[i].bz=i,a[i].v=did(a[i].s);
        
    }
    sort(a+1,a+n+1,cmp);
    int l=1;
    int sum=0;
    for (int i=1;i<=n;i++)
        if (a[i].s.size()!=a[l].s.size()){
            work(l,i-1);
            l=i;
            ++sum;
        }
    work(l,n);
    for (int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}
