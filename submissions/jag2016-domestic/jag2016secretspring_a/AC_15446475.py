n=int(input())
cur=0
for i in range(n):
  if (input()=="A"):
    cur+=1
  else:
    cur-=1
  if (cur<0):
    print("NO")
    exit()
if (cur==0):
  print("YES")
else:
  print("NO")
