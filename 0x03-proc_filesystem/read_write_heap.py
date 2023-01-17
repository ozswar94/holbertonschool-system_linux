#!/usr/bin/python3

import sys


if __name__ == "__main__":
	#check argument size
	if len(sys.argv) != 4:
		print("Error Usage: ./read_write_heap.py [pid] [search_string] [replace_string]")
		sys.exit(1)

	filename_maps = "/proc/{}/maps".format(sys.argv[1])
	filename_mem = "/proc/{}/mem".format(sys.argv[1])
	search = sys.argv[2]
	replace = sys.argv[3]
	try:
		with open(filename_maps, "r") as maps, open(filename_mem, 'rb+', 0) as mem:
			print("[*] The file {} is Open!".format(filename_maps))
			print("[*] The file {} is Open!".format(filename_mem))
	
			for line in maps.readlines():
				if "[heap]" in line:
					heap = line
					break

			heap = heap.split(" ")[0].split('-')
			start = int(heap[0], 16)
			end = int(heap[1], 16)
			print("[*] Heap start =", hex(start), "end = ", hex(end))

			mem.seek(start)
			content = mem.read(end - start)
			offset = content.find(bytes(search, 'ASCII'))
			print("[*] {} Find in HEAP!".format(search))
			mem.seek(start + offset)
			mem.write(bytes(replace + "\0", 'ASCII'))
			print("[*] {} > {}".format(search, replace))
	except Exception:
		print("Error in script !")
		sys.exit(1)
