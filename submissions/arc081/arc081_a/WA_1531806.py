#coding utf-8
import numpy as np
_=input()
bars=[i for i in map(int,input().split())]
np_data=np.array(bars)
bars.sort(reverse=True)

stock=[]
len_stock=0
ret=0
_old=-1
for bar in bars:
    if bar==_old:
        continue
    _old=bar
    count=len(np.where(bar))
    if count>=4:
        if len_stock!=0 and  bar not in stock:
            #print("ret bar bar")
            ret=bar*stock[0]
        else:
            #print("ret bar bar")
            ret=bar*bar
        break
    elif count>=2:
        if bar in stock:
            continue
        stock.append(bar)
        len_stock+=1
        if len_stock==2 :
            #print("ret stock stock")
            ret=stock[0]*stock[1]
            break
print(ret)