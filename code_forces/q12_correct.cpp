#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int mn=1e5+9;
const int mm=2e4+9;
long long sum[mn];
long long hh[mm],tt[mm];
long long f[mm];
int lowbit(int x)
{
  return x&(-x);
}
void update(int x)
{
  for(int i=x;i<mn;i+=lowbit(i))
  {
    sum[i]++;
  }
}
int query(int x)
{ int ret=0;
  for(int i=x;i>0;i-=lowbit(i))
  {
    ret+=sum[i];
  }
  return ret;
}
int main()
{
  int cas,n;
  while(~scanf("%d",&cas))
  {
    while(cas--)
    { memset(sum,0,sizeof(sum));
      scanf("%d",&n);
      int a;
      for(int i=0;i<n;++i)
      {
        scanf("%lld",&f[i]);
      }
      long long ans=0;
      for(int i=0;i<n;++i)
      {
        hh[i+1]=query(f[i]);
        update(f[i]);
      }
      memset(sum,0,sizeof(sum));
      for(int i=n-1;i>=0;--i)
      {
        tt[i+1]=query(f[i]);
        update(f[i]);
      }
      for(int i=1;i<=n;++i)
        ans+=hh[i]*((long long)(n-i-tt[i]))+(i-hh[i]-1)*(tt[i]);
      printf("%lld\n",ans);
    }
  }
  return 0;
}