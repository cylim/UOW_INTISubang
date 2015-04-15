A = [7, 17, 74, 21, 5, 9, 26, 10]

even = 0
odd = len(A)

while even < odd - 1:
	if A[even] % 2 == 0:
		even = even + 1
	else:
		odd = odd - 1
		A[even], A[odd] = A[odd], A[even]

print A