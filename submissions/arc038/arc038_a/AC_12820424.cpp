#include<bits/stdc++.h>
int main(){
	int n;
  	std::cin>>n;
  	std::vector<int> v(n);
    for (int i=0;i<n;i++){
    	std::cin>>v[i];
    }
  	std::sort(v.begin(),v.end(),std::greater<int>());
  	int ans=0;
  	for (int i=0;i<n;i++){
    	if (i%2==0)ans+=v[i];
    }
  	std::cout<<ans<<"\n";
  	return 0;
}