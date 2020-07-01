s=input()
t=input()
if (len(s)!=len(t)):
  print(-1)
  exit()
for i in range(len(s)):
  if (s[:len(s)-i]==t[i:]):
    print(i)
    exit()
print(len(s))