n=int(input())
l=list(map(int,input().split()))
ans=[0]*30
for i in l:
  ans[i]+=1
for i in ans:
	print(i,end=" ")