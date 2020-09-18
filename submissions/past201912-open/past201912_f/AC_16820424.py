s=input()
l=[]
cur=''
for c in s:
  cur+=c
  if (c==c.upper() and len(cur)>=2):
    l.append(cur)
    cur=''
l.sort(key=lambda x:x.upper())
print(''.join(l))