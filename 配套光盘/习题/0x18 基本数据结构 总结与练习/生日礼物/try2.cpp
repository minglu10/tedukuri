#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> P;
const int N=100010;
const int INF=0x3f3f3f3f;
int n,m,a[N],b[N],l[N],r[N];
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        while(a[n]<=0)
            n--;
        int st=1;
        while(a[st]<=0)
            st++;
        int cnt=0,ans=0;
        for(;st<=n;st++) {
            if(!((a[st]>0)^(a[st-1]>0)))
                b[cnt]+=a[st];
            else 
                b[++cnt]=a[st];
        }
        for(int i=1;i<=cnt;i++) {
            if(b[i]>0) {
                ans+=b[i];
                m--;
            }
            else 
                b[i]=-b[i];
        }
        if(m>=0){printf("%d\n",ans);continue;}
        priority_queue<P,vector<P>,greater<P> >Q;
        for(int i=1;i<=cnt;i++) {
            l[i]=i-1,r[i]=i+1,Q.push(P(b[i],i));
        }
        r[cnt]=0;
        for(int i=1;i<=-m;i++){
            while(b[Q.top().second]!=Q.top().first)Q.pop();
            int x=Q.top().second;
            Q.pop();
            ans-=b[x];
            if(!l[x]){
                b[r[x]]=INF;l[r[x]]=0;
            }
            else if(!r[x]){
                b[l[x]]=INF;r[l[x]]=0;
            }
            else{
                b[x]=b[l[x]]+b[r[x]]-b[x];
                b[l[x]]=b[r[x]]=INF;
                r[l[x]=l[l[x]]]=l[r[x]=r[r[x]]]=x;
                Q.push(P(b[x],x));
            }
        }printf("%d\n",ans);
    }return 0;
}
