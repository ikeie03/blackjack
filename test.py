import ctypes
from ctypes import CDLL, c_double, c_int
shared_library = ctypes.CDLL('./monte_carlo.dylib')

simulateBlackJack = shared_library.simulateBlackJack

simulateBlackJack.argtypes = [c_int, c_double, c_double,
                          c_double, c_double, c_double, c_double,
                          c_double, c_double, c_double, c_double,
                          c_double, c_double, c_double]

simulateBlackJack.restype = c_double

get_std_dev = shared_library.get_std_dev
get_std_dev.restype = c_double



print(get_std_dev())

x = simulateBlackJack(6, 0.01, 1000000, 
                  -1, 1, 1, 1, 1, 1, 0, 0, 0, -1)

std_dev_x = get_std_dev()

y = simulateBlackJack(6, 0.01, 1000000, 
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

std_dev_y = get_std_dev()

print('with counting:', x, 'standard deviation:', std_dev_x)
print('without counting:', y, 'standard deviation:', std_dev_y)