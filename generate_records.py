#!/usr/bin/python
#coding=utf-8
#generate the content of records.txt#02# 4 test
from random import random

def main():
	print "1\tname1\t1.65"
	for i in range(2,6):
		print "%d\tna me%d\t%.2f" % (i, i, 1.5 + random()*0.4)

if __name__ == '__main__':
	main()
