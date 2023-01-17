#!/usr/bin/python3


import sys
import os


if __name__ == "__main__":
	#check argument size
	if len(sys.argv) != 4:
		print("Error Usage: ./read_write_heap.py [pid] [search_string] [replace_string]")
		sys.exit(1)

	filename_maps = "/proc/{}/maps".format(sys.argv[1])
	filename_mem = "/proc/{}/mem".format(sys.argv[1])
	search = sys.argv[2]
	replace = sys.argv[3]

	with open(filename_maps, "r") as maps, open(filename_mem, 'r', 0) as mem:
		for line in maps.readlines():
			if "[heap]" in line:
				heap = line
				break
		heap = heap.split(" ")[0].split('-')
		start = int(heap[0], 16)
		end = int(heap[1], 16)
		print(heap, hex(start), hex(end))

