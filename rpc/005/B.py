d1, m1, y1, WD = map(int, input().split())
d2, m2, y2 = map(int, input().split())

newWD = ((((360*(y2-y1))+(30*(m2-m1))+(d2-d1))%7)+ WD - 1)%7

print(newWD + 1)