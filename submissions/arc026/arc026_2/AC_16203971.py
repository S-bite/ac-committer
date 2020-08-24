n=int(input())
i=1
divsum=0
while(i*i<n):
  if (n%i==0):
    divsum+=i+n//i
  i+=1
divsum-=n
if (divsum==n):
  print("Perfect")
elif (divsum<n):
  print("Deficient")
else:
  print("Abundant")