def read_int():
	return int(input())

def read_ints():
	return map(int, input().split(' '))

def main():
	n = read_int()
	if n < 4:
		if n == 1:
			print(0)
		else :
			print(1)
		return
	a = [0] * (n + 1)
	a[2] = a[3] = 1
	for i in range(4, n + 1):
		a[i] = 	a[i - 3] + 2 * a[i - 2] + a[i - 1]
	print(a[-1])
	

if __name__ == "__main__":
	main()