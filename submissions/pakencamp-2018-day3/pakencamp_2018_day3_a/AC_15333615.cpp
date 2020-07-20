#include<bits/stdc++.h>
using namespace std;
int main(){
	int y,m,d;
  	cin>>y>>m>>d;
  	if (m!=12 || d!=25){
    	cout<<"NOT CHRISTMAS DAY"<<endl;
    }else{
    	cout<<y-2018<<endl;
    }
	return 0;
}