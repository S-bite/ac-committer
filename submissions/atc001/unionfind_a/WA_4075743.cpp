#include<bits/stdc++.h>
using namespace std;
class UF{
    private:
    public:
    UF *root;
    int value;
    UF(int n=0){
        root=this;
        value=n;
    }
    void showInfo(void){
        cout<<"rootNode:"<<root<<",value:"<<value<<endl;
    }
};

void connectNode(UF *a,UF *b){
    //while(b->root!=b)b=b->root;
    //while(a->root!=a)a=a->root;
    
    if(a>b){
        a->root=b;
        }
    if (a<b){
     b->root=a;
    }
    return;
}
bool hasSameRoot(UF *a,UF *b){

    while(a->root!=a)a=a->root;
    while(b->root!=b)b=b->root;
    return a==b;
}
int main(){
    int n,q;
    cin>>n>>q;

    UF u[n];
    //for(int i=0;i<n;i++) u[i].showInfo();
    for (int i=0;i<q;i++){
        int p,a,b;
        cin>>p>>a>>b;
        if (p==0) connectNode(&u[a],&u[b]);
        if (p==1)cout<<(hasSameRoot(&u[a],&u[b])?"Yes":"No")<<endl;
    }
    return 0;
}