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
    a=math.floor((k)/N)+1
    a=int(a)
    l=[a+i for i in range(50)]
    mod=N-k%N
    for i in range(mod):
        l=f(l)
    print(50)
    for i in range(50):
        print(str(l[i])+" ",end="")
    print("")
    ret=0
    #while (max(l)>=50):
    #    l=f(l)
    #    ret+=1
    #if (ret!=k):
    #    print("error:",k)
    #    exit()
solve(int(input()))