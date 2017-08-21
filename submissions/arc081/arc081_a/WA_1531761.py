#coding utf-8
_=input()
bars=[i for i in map(int,input().split())]
bars.sort(reverse=True)
stock=[]
ret=0
for bar in bars:
    count=bars.count(bar)
    if count>=4:
        if len(stock)!=0 and bar not in stock:
            ret=bar*stock[0]
        else:
            ret=bar*bar
        break
    elif count>=2:
        stock.append(bar)
        if len(stock)==2:
            ret=stock[0]*stock[1]
            break
print(ret)