import numpy as np
import matplotlib.pyplot as plt
from matplotlib import animation

x = np.linspace(0, 100, 200)
data = np.loadtxt('cuerda.txt')

fig = plt.figure()
ax = plt.axes(xlim=(0,100), ylim=(-1, 1))
line, = ax.plot(x, data[:,0], lw = 2)
plt.xlabel('x')
plt.ylabel('U(x,t)')
plt.title('Cuerda Vibrando')

def animate(i):

    line.set_ydata(data[i,:])
    return line,

mov = animation.FuncAnimation(fig, animate, init_func = init, frames = np.arange(1, len(data[1])), interval = 50)
mov.save('cuerda.gif')



