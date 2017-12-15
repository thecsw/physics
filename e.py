import math

lim = 9999999999.0
e1 = math.pow((1.0+(1.0/lim)), lim)
e2=0
for n in range(0, 101):
    e2+=(1.0*n/math.factorial(n))

print('{0:.50f}'.format(e1))
print('{0:.50f}'.format(e2))
