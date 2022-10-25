import numpy as np
deaths = [73, 71, 83, 72, 195, 126, 89, 103, 95, 128, 97, 87, 122, 134, 100, 103, 120, 157, 134, 140, 132, 148, 137, 147, 154, 146, 170, 194, 175, 265, 193]
days = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31]
m = 22
A = 0
B = 0
C = 0
D = 0
for x in range(0, m):
	A += days[x]
	B += deaths[x]
	C += days[x] * days[x]
	D += deaths[x] * (days[x])

w0 = (B * C - A * D) / (m * C - A * A)
w1 = (A * B - m * D) / (A * A - m * C)
print("Squared error in linear fitting : ", end = "")
linear_error = 0
for x in range(22, 31):
	linear_error += (w0 + w1 * days[x] - deaths[x]) * (w0 + w1 * days[x] - deaths[x])
print(linear_error)

d1 = -10
d2 = 102
deaths1 = w0 + w1 * d1
deaths2 = w0 + w1 * d2
print("deaths on day 1 : ", end = "")
print(deaths1)
print("deaths on day 2 : ", end = "")
print(deaths2)
print()