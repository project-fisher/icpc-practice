t = int(input())
for _ in range(t):
	n, d = map(int, input().split())
	ans = 1
	d += 1
	m = d
	while m < n:
		ans += 1
		m *= d
	print(ans)
