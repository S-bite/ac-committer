#coding utf-8
_=input()
bars=[i for i in map(int,input().split())]
bars.sort(reverse=True)
stock=[]
ret=0
for bar in bars:
    count=bars.count(bar)
    if count>=4:
        if len(stock)!=0 and  bar not in stock:
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
        if len(stock)==2 :
            #print("ret stock stock")
            ret=stock[0]*stock[1]
            break
print(ret)