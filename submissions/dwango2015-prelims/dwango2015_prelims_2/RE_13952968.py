s=input()
if (len(s)%2==1):
  s+="@"
ans=0
cur=0
for i in range(len(s)):
  if (s[i]=="2" and s[i+1]=="5"):
    i+=1
    cur+=1
  else:
    ans+=((cur+1)*cur)//2
    cur=0
print(cur)