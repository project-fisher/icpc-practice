n, x = map(int, input().split())
prev_price = 0
best = -1
for i in range(min(n, x)):
	a, b = map(int, input().split())
	prev_price += a
	att = prev_price + (x - i)*b
	if best == -1 or best > att: best = att
	prev_price += b
print(best)
