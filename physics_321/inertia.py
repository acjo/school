#inertia.py

import numpy as np
import sympy as sy
from matplotlib import pyplot as plt

def compute_product_of_inertia_discrete(positions, masses, i, j):
    value = 0
    for pos, mass in zip(positions, masses):
        value += mass*pos[i]*pos[j]
    return value

def compute_inertia_tensor_discrete(positions, masses):
    ten = sy.Matrix(np.zeros((3, 3)))
    for i in range(3):
        for j in range(3):
            if i == j:
                if i == 0:
                    ten[i, j] = compute_product_of_inertia_discrete(positions, masses, 1, 1)

                    ten[i, j] +=compute_product_of_inertia_discrete(positions, masses, 2, 2)
                elif i == 1:
                    ten[i, j] = compute_product_of_inertia_discrete(positions, masses, 0, 0)

                    ten[i, j] += compute_product_of_inertia_discrete(positions, masses, 2, 2)
                else:
                    ten[i, j] = compute_product_of_inertia_discrete(positions, masses, 1, 1)

                    ten[i, j] += compute_product_of_inertia_discrete(positions, masses, 0, 0)

            else:
                ten[i, j] = -1*compute_product_of_inertia_discrete(positions, masses, i, j)

    return ten


if __name__ == "__main__":
    a, m = sy.symbols('a, m')
    v1 = sy.Matrix([a, 0, 0])
    v2 = sy.Matrix([0, a, a])
    v3 = sy.Matrix([0, a, -a])
    masses = [m, 2*m, 3*m]
    positions = [v1, v2, v3]

    print(compute_inertia_tensor_discrete(positions, masses))
    V1 = np.array([1, 0, 0])
    V2 = np.array([0, 1, 1])
    V3 = np.array([0, 1, -1])
    VS = [V1, V2, V3]

    fig = plt.figure()
    fig.set_dpi(150)
    ax = fig.add_subplot(111, projection='3d')
    for V in VS:
        ax.plot(V[0], V[1], V[2], 'ro', markersize=3)

    plt.show()



