#!/usr/bin/python
#coding=utf-8
last = -25
lastlast = 25

print "1:", lastlast
print "2:", last
for i in range(3, 10):
	this = ((last*4627 + lastlast*3581)/100)%100 - 50
	print "%d: %d" % (i, this)
	lastlast = last;
	last = this;

