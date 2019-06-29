import math

def f(l):
    mx=max(l)
    flg=True
    for i in range(len(l)):
        if (mx==l[i] and flg==True):
            flg=False
            l[i]-=50
        else:
            l[i]+=1
    return l



k=int(input())
N=50
a=math.ceil(k/N)
a=int(a)
l=[a+i for i in range(50)]
mod=N-k%N
for i in range(mod):
    l=f(l)
print(50)
for i in range(50):
    print(str(l[i])+" ",end="")
print("")

