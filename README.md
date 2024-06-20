# UniC

### Version 1.9

### Latest features & changes

- DoubleLinkedList
- Heap
- Graph
- new utils types

### TO-DO

- Graph algorithms
- Add examples

## About

General purpose library

Feel free to use it, but please note:

- it's not optimized for performance
- it could be obviously improved

### Linking

```sh
# go inside UniC path
cd <lib path>
# compile library
make
# link library
gcc ... <lib path>/UniC.a
```

## Data structures

- Matrices
- Vector
- Node
- Linked list
- Double linked list
- Queue
- Stack
- Binary tree
- Dictionary (Hash map)
- Heap
- Graph

## Algorithms

- Search
- Sort

## Libft

Basic implementation

## Examples

Compile the library before running any example

### Graph

- Generate a graphical representation of the graph using mermaid ([repo](https://github.com/mermaid-js/mermaid))

	```make
	make graphdraw
	```
	output:
	```mermaid
	flowchart LR
	0((a)) -- 2 --> 1((b))
	0((a)) -- 1 --> 3((d))
	1((b)) -- 4 --> 2((c))
	1((b)) -- 1 --> 4((e))
	2((c))
	3((d)) -- 3 --> 4((e))
	4((e)) -- 2 --> 5((f))
	5((f)) -- 6 --> 4((e))
	5((f)) -- 3 --> 2((c))
	5((f)) -- 1 --> 0((a))
	```

