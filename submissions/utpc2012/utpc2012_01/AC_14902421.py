s=input()
t=s[:4]
t="".join(sorted(t))
s="".join(sorted(s[-1]+s[-2]+s[-4]+s[-5]))
print("yneos"[s!=t::2])