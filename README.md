# dynamic_lists

**Linked list** is a dynamic list structure that uses doubly linked nodes. Each node has a value, a next node, and a previous node. The linked list keeps track of the head and tail.\
**Array list** is a dynamic list structure that uses simple arrays.\
Array list can add, insert, remove, and get.
- add will allocate or reallocate memory for the array to increase its size, and insert the input value at the end of the array.
- insert will reallocate memory for the array to increase its size. It will shift values to the right to make a hole at the input index, and will insert the the input value at the index
- remove will create a temporary array that copies the original array, but skips the removed index. The original array is destryed, then memory is allocated to an appropriate size. The original array then copies the temporary array.
- get simply returns the value at a given index
