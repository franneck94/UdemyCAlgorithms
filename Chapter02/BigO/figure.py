import numpy as np
import scipy.special
import matplotlib.pyplot as plt

upper = 20

x = np.arange(
    start=0,
    stop=upper,
    step=1,
    dtype=np.float64
)

const = np.zeros_like(x)
log_n = np.log2(x)
linear = x.copy()
n_log_n = x * np.log2(x)
quadratic = np.square(x)
exp = 2**x
fac = scipy.special.factorial(x)

plt.plot(x, const, color="red")
plt.plot(x, log_n, color="blue")
plt.plot(x, linear, color="green")
plt.plot(x, n_log_n, color="cyan")
plt.plot(x, quadratic, color="orange")
plt.plot(x, exp, color="yellow")
plt.plot(x, exp, color="lightblue")
plt.legend([
    "$1$",
    "$\log n$",
    "$n$",
    "$n \log n$",
    "$n^2$",
    "$2^n$",
    "$n!$"
])
plt.ylim((0, upper*upper))
# plt.show()
plt.savefig("big_o.svg")
