// This file is a "Hello, world!" in C language by gcc for wandbox.
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin>>n;
    int mx=-1,mn=1001;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        mx=max(mx,t);
        mn=min(mn,t);
    }
    cout<<(mx-mn)<<endl;
    return 0;
}

// GCC reference:
//   https://gcc.gnu.org/

// C language references:
//   https://msdn.microsoft.com/library/fw5abdx6.aspx
//   https://www.gnu.org/software/gnu-c-manual/
