from math import sqrt, floor, ceil

a, b = map(int, input().split())

t = 0

def f(x):
	return a/sqrt(x + 1) + x*b

def fp(x):
	return -a/(x + 1)/sqrt(x + 1)/2 + b

inf = 0
sup = 1 << 64
mid = (inf + sup)/2
epsilon = 10**-8
count = 0

while not (fp(mid - 1) - epsilon <= 0 <= fp(mid - 1) + epsilon):
	if fp(mid - 1) > epsilon: sup = mid
	else: inf = mid
	mid = (inf + sup)/2
	count += 1
	if count > 1000: break

mid -= 1
if mid <= 0: print("%.13f" % min(f(0), f(1)))
elif mid < 1: print("%.13f" % min(f(floor(mid)), f(ceil(mid)), f(ceil(mid) + 1)))
else: print("%.13f" % min(f(floor(mid) - 1), f(floor(mid)), f(ceil(mid)), f(ceil(mid) + 1)))
