import matplotlib.pyplot as plt
import numpy as np
from matplotlib.animation import FuncAnimation

# 创建画布和子图
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

# 初始化 x 和 y 数据
x = np.linspace(0, 2 * np.pi, 5000)
y = np.exp(-x) * np.cos(2 * np.pi * x)

# 绘制初始曲线
(line,) = ax.plot(x, y, color="cornflowerblue", lw=3)
ax.set_ylim(-1.1, 1.1)


# 清空当前帧
def init():
    line.set_ydata([np.nan] * len(x))
    return (line,)


# 更新新一帧的数据
def update(frame):
    line.set_ydata(np.exp(-x) * np.cos(2 * np.pi * x + float(frame) / 100))
    return (line,)


# 创建动画
ani = FuncAnimation(fig, update, init_func=init, frames=200, interval=2, blit=True)

# 保存为 GIF 图片
ani.save("turing_machine_animation.gif", fps=25, writer="imagemagick")
