import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('caos.txt')
plt.figure()
plt.plot(data[:,1], data[:,0], label = ' Comportamiento variables')
plt.xlabel('p2')
plt.ylabel('q2')
plt.ylim((-5000, 5000))
plt.title('q2 vs. p2')
plt.legend()

plt.savefig('caos.pdf')
