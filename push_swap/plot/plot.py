import matplotlib.pyplot as plt
import numpy as np
import sys
from math import log

push_swap = []
for i in range(5, int(sys.argv[1]) + 1, 5):
    value = 0
    with open(f"test/test_push_swap{i}.txt", "r") as f:
        for x in f:
            if value < int(x):
                value = int(x)
        push_swap.append(value)

# make data
x = np.linspace(5, int(sys.argv[1]), int(sys.argv[1]) // 5)
y_100 = [700 for i in x]
y_500 = [5500 for i in x]
log_y_100 = []
log_y_500 = []
log_x = []
log_push_swap = []
for elem in y_100:
    log_y_100.append(log(elem, 10))
for elem in y_500:
    log_y_500.append(log(elem, 10))
for elem in x:
    log_x.append(log(elem, 10))
for elem in push_swap:
    log_push_swap.append(log(elem, 10))
for i in range(len(log_push_swap)):
    if (log_push_swap[i] > log_y_100[0]):
        y_1 = (log_push_swap[i - 1] + log_push_swap[i]) / 2
        x_1 = log_x[i]
        break
for i in range(len(log_push_swap)):
    if (log_push_swap[i] > log_y_500[0]):
        y_2 = (log_push_swap[i - 1] + log_push_swap[i]) / 2
        x_2 = log_x[i]
        break
a = (y_2 - y_1) / (x_2 - x_1)
b = y_1 - (a * x_1)
final_a = (1.385 + 1.405 + 1.419 + 1.372 + 1.345 + 1.379 + 1.365 + 1.392 + 1.420) / 9
delta_final_a = (1.420 - 1.345) / 2
print("A: ", a)
print("B: ", b)
print("a \u00B1 \u0394a: ", round(final_a, 3), " \u00B1 ",round(delta_final_a, 3))
fit_log = [(i * a) + b for i in log_x]
fit = [(i ** a) for i in x]
final_fit_1 = [(i ** (final_a + delta_final_a)) for i in x]
final_fit_2 = [(i ** (final_a - delta_final_a)) for i in x]
# plot
fig, axs = plt.subplots(1, 2, figsize=(16, 10))

axs[0].plot(x, push_swap, linewidth=1.0)
axs[0].plot(x, y_100, linestyle="dashed", linewidth=1.0, color="black")
axs[0].plot(x, y_500, linestyle="dashed", linewidth=1.0, color="red")
axs[0].plot(x, fit, linestyle="dashed", linewidth=1.0, color="green")
axs[0].plot(x, final_fit_1, linestyle="dashed", linewidth=1.0, color="grey")
axs[0].plot(x, final_fit_2, linestyle="dashed", linewidth=1.0, color="grey")
axs[0].set_xlim(left=5.0)
axs[0].set_ylim(bottom=5.0)
axs[0].set_xlabel('length of stack', fontsize='15')
axs[0].set_ylabel('number of moves', fontsize='15')
axs[0].grid(True)
axs[0].legend(('p_s', 'y_100', 'y_500', 'fit'), shadow=True, loc='upper left')
axs[0].set_title('push_swap', fontsize='20')
axs[1].plot(log_x, log_push_swap, linewidth=1.0)
axs[1].plot(log_x, log_y_100, linestyle="dashed", linewidth=1.0, color="black")
axs[1].plot(log_x, log_y_500, linestyle="dashed", linewidth=1.0, color="red")
axs[1].plot(log_x, fit_log, linestyle="dashed", linewidth=1.0, color="green")
axs[1].set_xlim(left=log(5.0, 10))
axs[1].set_ylim(bottom=log(5.0, 10))
axs[1].set_xlabel('log(length of stack)', fontsize='15')
axs[1].set_ylabel('log(number of moves)', fontsize='15')
axs[1].grid(True)
axs[1].legend(('log(p_s)', 'log(y_100)', 'log(y_500)', 'fit'), shadow=True, loc='upper left')
axs[1].set_title('log(push_swap)', fontsize='20')
plt.show()
