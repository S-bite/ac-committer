s=input()
while "  " in s:
	s=s.replace("  "," ")
s=s.replace(" ",",")
print(s)
