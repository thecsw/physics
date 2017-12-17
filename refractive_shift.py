import matplotlib.pyplot as plt
import math

n1 = 1
n2 = 1.5
d = 2.7
PI = 3.14159265
a = 0
angles = []
for a in range(0, 91):
    x = ((d*(math.cos(a*(PI/180)+math.asin((n1*math.cos(a*(PI/180)))/(n2)))))/(math.cos(math.asin((n1*math.cos(a*(PI/180)))/(n2)))))
    angles.append(x)
    print("{} degrees is : {}".format(a, x))

plt.plot(range(len(angles)), angles)
plt.ylabel('Refractive shift')
plt.xlabel('Angle in degrees')
plt.title('Relationship between horizontal incident angle and refractive shift with glass thickness : {}'.format(d))
plt.show()
