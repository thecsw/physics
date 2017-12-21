import math
import matplotlib.pyplot as plt
import time

a = 0.2
b = 6
lim = 200
w = []
p = []
i = -2
o = 0
begin = time.time()
#while b < 10:
#    i = -2
while i < 2:
    x = 0
    for n in range(0, lim):
        cosx =  math.cos(math.pow(b, n) * math.pi * i)
        x += math.pow(a, n) * cosx
    w.append(x)
    p.append(i)
    print(i)
    i+=0.001
#   b+=0.1
#   o+=1
plt.title("a = {}, b = {}".format(a, b))
plt.plot(p, w, linewidth=0.5)
#    p = []
#    w = []
#    plt.savefig('Weierstrass-Color/{}.png'.format(o), dpi=300, format='png')
#plt.clf()
end = time.time()
print("Execution time : {} seconds".format(end-begin))
plt.show()
