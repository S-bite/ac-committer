#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
int asc(const void *a,const void *b){
return *(int *)b - *(int *)a;
}
int main(int argc,char *argv[]){
 int n,k;
 scanf("%d%d",&n,&k);
 int a[n],ans=0;
 rep(i,n)scanf("%d",&a[i]);
 qsort((void *)a,n,sizeof(a[0]),asc);
 rep(i,k)ans+=a[i];
 printf("%d\n",ans);
 return 0;
}
