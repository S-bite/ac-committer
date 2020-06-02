s=input()
if (len(s)%2==1):
  s+="@"
ans=0
cur=0
i=0
while(i<len(s)):
  if (s[i]=="2" and s[i+1]=="5"):
    i+=2
    cur+=1
    continue
  else:
    ans+=((cur+1)*cur)//2
    cur=0
  i+=1
ans+=((cur+1)*cur)//2
print(ans)
