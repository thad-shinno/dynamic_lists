# dynamic_lists

**Linked list** is a dynamic list structure that uses doubly linked nodes. Each node has a value, a next node, and a previous node. The linked list keeps track of the head and tail.\
Linked list can add, insert, remove, and get.
- *add*: if the list is empty, the the new node becomes the head and tail, and head and tail will be doubly linked to each other. If there is already content in the list, then the new node's previous is the tail, and the new node becomes the tail
- *insert*: If the new node is inserted at the tail, it just adds. If it's added at the head, then the new node's next becomes the head, then the head becomes the new node. If the new node is inserted anywhere in between the head and tail, then the new node is doubly linked to the surrounding nodes, then the surrounding nodes are linked to the new nodes.
- *remove* simply links nodes to the next next and prev prev in order to unlink a node, effectivly removing it from the list.
- *get* iterates and returns the node at the specified index.
**Array list** is a dynamic list structure that uses simple arrays.\
Array list can add, insert, remove, and get.
- *add* will allocate or reallocate memory for the array to increase its size, and insert the input value at the end of the array.
- *insert* will reallocate memory for the array to increase its size. It will shift values to the right to make a hole at the input index, and will insert the the input value at the index
- *remove* will create a temporary array that copies the original array, but skips the removed index. The original array is destryed, then memory is allocated to an appropriate size. The original array then copies the temporary array.
- *get* simply returns the value at a given index
