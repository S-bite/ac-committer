#include<bits/stdc++.h>

int main(){
	int n;
  	std::cin>>n;
  	std::vector<int> v(n);
  	for(int i=0;i<n;i++){
    	std::cin>>v[i];
    }
  	std::sort(v.begin(),v.end());
  	int ans=0;
  	for (int i=0;i<n-1;i++){
    	if (v[i+1]-v[i]<=1){
    		ans++;
          	i++;
        }
    }
  	std::cout<<ans<<"\n";
	return 0;
}