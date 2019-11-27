#include<stdio.h>
int main(){
	int n,x,y,z,i,a[100],b[100],ans=0;
  	scanf("%d%d%d%d",&n,&x,&y,&z);
  	for (i=0;i<n;i++){
    	scanf("%d%d",&a[i],&b[i]);
    }
  	for (i=0;i<n;i++){
    	if ((a[i]>=x && b[i]>=y)&&(a[i]+b[i]>=z)){
        	ans++;
        }
    }
  	printf("%d\n",ans);
	return 0;
}
