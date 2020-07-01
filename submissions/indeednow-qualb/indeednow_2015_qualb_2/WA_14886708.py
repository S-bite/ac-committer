s=input()
t=input()
if (len(s)!=len(t)):
  print(-1)
  exit()
for i in range(len(s)+1):
  s=s[-1]+s[:-1]
  if (s==t):
    print(i+1)
    exit()
