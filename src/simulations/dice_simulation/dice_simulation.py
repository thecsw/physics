import matplotlib.pyplot as plt
import random

dices = 1000
decay = []
while not dices == 1:
    for i in range(0, dices):
        if random.randint(1,6) == 6:
            dices-=1
    decay.append(dices)
    print(dices)
plt.plot(range(len(decay)), decay)
plt.show()
