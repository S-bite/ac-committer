#include<bits/stdc++.h>

int main(){
	int n;
  	std::cin>>n;
  	std::vector<int> v(n);
  	for(int i=0;i<n;i++){
    	std::cin>>v[i];
    }
  	int ans=0;
	int cur=0;
  	for (int i=0;i<n;i++){
		ans+=(v[i]+cur)/2;
      	if (v[i]!=0)
	      	cur=(v[i]+cur)%2;
    	else
          	cur=0;
    }
  	std::cout<<ans<<"\n";
	return 0;
}
