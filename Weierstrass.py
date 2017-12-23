import math
import matplotlib.pyplot as plt
import time
# Comments are the version for animations.
demo = input("Would you like the demo version with default values? (Y/n) ")
if demo == 'Y':
    a = 0.2
    b = 4.5
    iteration_step = 0.001
    min_x = -2
    max_x = 2
else:
    a = input("Please input value for a : ")
    b = input("Please input value for b : ")
    iteration_step = input("Please input the iteration value, less is more accurate (Default = 0.001) : ")
    min_x = input("Lower boundary for x : ")
    max_x = input("Upper boundary for x : ")
y_values = []
x_values = []
iteration_limit = 200
begin = time.time()
x = min_x
while x < max_x:
    f = 0
    for n in range(0, iteration_limit):
        cosx =  math.cos(math.pow(b, n) * math.pi * x)
        f += math.pow(a, n) * cosx
    y_values.append(f)
    x_values.append(x)
    x += iteration_step
plt.title("Weierstrass function with parameteres : a = {}, b = {}".format(a, b))
plt.plot(x_values, y_values, linewidth = 0.5)
end = time.time()
print("Execution time : {} seconds".format(end-begin))
plt.show()
