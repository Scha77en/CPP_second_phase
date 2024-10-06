import os
import random

test_number = 0

max_tess = (4000 - 2 + 1) * 3

for n in range(2, 4000):
	for i in range(3):
		lst = list(range(n))
		origin = list(lst)
		if (i == 0):
			lst = lst[::-1]
		else:
			random.shuffle(lst)
		args = " ".join(map(str, lst))
		cmd = "./PmergeMe " + args + " > out.txt"
		os.system(cmd)
		try:
			out = open("out.txt", "r").read()
			out = out[out.index("Before:"):]
			out = out[out.index("After:") + len("After:"):]
			out = out[:out.index("Time")].strip().split(" ")
			out = map(int, out)
			if (out != sorted(origin)):
				print ("Fail")
				print (cmd)
				exit()
		except:
			print ("Fail")
			print (cmd)
			print (out)
			exit()
	test_number += 1
	print (test_number, "/", max_tess)
