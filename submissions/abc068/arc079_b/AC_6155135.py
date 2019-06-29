import math

def f(l):
    mx=max(l)
    flg=True
    for i in range(len(l)):
        if (mx==l[i] and flg==True):
            flg=False
            l[i]-=50
            l[i]=max(0,l[i])
        else:
            l[i]+=1
    return l


def solve(k):
    #k=int(input())
    N=50
    a=k//N+1
    if (k%N==0) :
        a-=1
    l=[a+i for i in range(50)]
    mod=(N-(k%N))%N
    for i in range(mod):
        l=f(l)
    l=sorted(l,reverse=True)
    print(50)
    for i in range(50):
        print(str(l[i])+" ",end="")
    print("")
    ret=0
solve(int(input()))