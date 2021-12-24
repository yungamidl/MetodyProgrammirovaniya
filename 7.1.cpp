def pr(s):
   p = [0] * len(s)
   for i in range(1, len(s)):
       k = p[i - 1]
       while k > 0 and s[k] != s[i]:
           k = p[k - 1]
       if s[k] == s[i]:
            k += 1
            p[i] = k
   return p

line = input()
x = pr(line)
res = len(line) / (len(line) - x[len(x)-1])
if res.is_integer():
   print(int(res))
else:
   print(1)
