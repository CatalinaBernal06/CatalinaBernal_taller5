import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('placas.txt')

N = 512
L = 5.0

x = np.linspace(-L/2.0, L/2.0, N)
y = np.linspace(-L/2.0, L/2.0, N)

dat = data.reshape((N, N, 3))
#diverging colormaps
plt.imshow(dat[:,:,0], extent = [-L/2.0, L/2.0, -L/2.0, L/2.0], cmap = 'BrBG')
plt.colorbar()
plt.xlim(-L/2.0, L/2.0)
plt.ylim(-L/2.0, L/2.0)
plt.streamplot(x, y, dat[:,:, 1], dat[:,:, 2], color = 'k')
plt.title('Campo El$\'e$ctrico y Potencial')
plt.savefig('placas.pdf')
