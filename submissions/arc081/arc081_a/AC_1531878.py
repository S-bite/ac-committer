#coding utf-8
import collections
_=input()
bars=[i for i in map(int,input().split())]
data=sorted(collections.Counter(bars).items(),key= lambda x: -x[0] )
stock=0
ret=0
for bar ,count in data:
    if count>=4:
        if stock:
            ret=stock*bar
            break
        else:
            ret=bar*bar
            break
    elif count>=2:
        if stock:
            ret=stock*bar
            break
        else:
            stock=bar
print(ret)
