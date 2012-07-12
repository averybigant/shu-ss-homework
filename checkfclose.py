#!/usr/bin/python
#coding=utf-8
import sys
#简单的统计文件中的fopen和fclose出现次数是否匹配，如果不匹配就输出

def main():
	path = sys.argv[1]
	with open(path, 'r') as f:
		content = f.read()
		if content.count("fopen") > content.count("fclose"):
			print "%s" % path

if __name__ == '__main__':
	main()
