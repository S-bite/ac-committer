i=input()
l=map(int,input().split())
ans=min(l[1],l[3])-max(l[0],l[2])
print(ans if ans>0 else 0)