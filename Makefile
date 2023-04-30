CC 		?= gcc
CFLAGS  ?= -pedantic -Wall
INC     := ./include/
RM      =  rm -rf 
IDIR    =  -I$(INC) 
VPATH   =  lists/:sorting/:tree/:search/

.PHONY: clean all

#%.o: %.c
#	$(CC) $(CFLAGS) $(IDIR) -c $^  

####        LIST   
# stack array 
stackarray: stackarray.o stackarraymain.o
	$(CC) $(CFLAGS) -o $@ $^ 

stackarray.o: stackarray.c 
	$(CC) $(CFLAGS) $(IDIR) -c $< -DARRAY_LIST

stackarraymain.o: stackarraymain.c
	$(CC) $(CFLAGS) $(IDIR) -c $< -DARRAY_LIST

# queue array
queuearray: queuearray.o queuearraymain.o
	$(CC) $(CFLAGS) -o $@ $^ 

queuearray.o: queuearray.c 
	$(CC) $(CFLAGS) $(IDIR) -c $< -DARRAY_LIST  -DCIRCULAR_Q  -DOPT_CIRCULAR_Q

queuearraymain.o: queuearraymain.c
	$(CC) $(CFLAGS) $(IDIR) -c $< -DARRAY_LIST  -DCIRCULAR_Q  -DOPT_CIRCULAR_Q

# linked list
linkedlist: linkedlist.o linkedlistmain.o
	$(CC) $(CFLAGS) -o $@ $^

linkedlist.o: linkedlist.c 
	$(CC) $(CFLAGS) $(IDIR) -c $<

linkedlistmain.o: linkedlistmain.c
	$(CC) $(CFLAGS) $(IDIR) -c $<

####    SORTING 
sortingmain: sortingmain.o stackarray.o bubble.o insertion.o merge.o quick.o selection.o heap.o
	$(CC) $(CFLAGS) -o $@ $^  -DARRAY_LIST 

sortingmain.o: sortingmain.c 
	$(CC) $(CFLAGS) $(IDIR) -c $< -DARRAY_LIST

bubble.o: bubble.c 
	$(CC) $(CFLAGS) $(IDIR) -c $< -DARRAY_LIST

insertion.o: insertion.c 
	$(CC) $(CFLAGS) $(IDIR) -c $< -DARRAY_LIST

merge.o: merge.c 
	$(CC) $(CFLAGS) $(IDIR) -c $< -DARRAY_LIST

quick.o: quick.c 
	$(CC) $(CFLAGS) $(IDIR) -c $< -DARRAY_LIST

selection.o: selection.c 
	$(CC) $(CFLAGS) $(IDIR) -c $< -DARRAY_LIST

heap.o: heap.c 
	$(CC) $(CFLAGS) $(IDIR) -c $< -DARRAY_LIST

####    TREE 
bstmain: binsearchtreemain.o binarysearchtree.o
	$(CC) $(CFLAGS) -o $@ $^  

binsearchtreemain.o: binsearchtreemain.c
	$(CC) $(CFLAGS) $(IDIR) -c $< 

binarysearchtree.o: binarysearchtree.c
	$(CC) $(CFLAGS) $(IDIR) -c $<  -DOPT_BST

minheaptreemain: minheaptreemain.o minheaptree.o
	$(CC) $(CFLAGS) -o $@ $^

minheaptreemain.o: minheaptreemain.c 
	$(CC) $(CFLAGS) $(IDIR) -c $< -DARRAY_LIST #-DTOP_DOWN

minheaptree.o: minheaptree.c 
	$(CC) $(CFLAGS) $(IDIR) -c $< -DARRAY_LIST #-DTOP_DOWN

avltreemain: avltreemain.o avltree.o
	$(CC) $(CFLAGS) -o $@ $^

avltreemain.o: avltreemain.c
	$(CC) $(CFLAGS) $(IDIR) -c $< 

avltree.o: avltree.c
	$(CC) $(CFLAGS) $(IDIR) -c $< 

####    searching 
searchmain: searchmain.o binsearch.o hashsearch.o linearsearch.o stackarray.o
	$(CC) $(CFLAGS) -o $@ $^       

searchmain.o: searchmain.c 
	$(CC) $(CFLAGS) $(IDIR) -c $<  -DARRAY_LIST

binsearch.o: binsearch.c 
	$(CC) $(CFLAGS) $(IDIR) -c $<  -DARRAY_LIST

hashsearch.o: hashsearch.c 
	$(CC) $(CFLAGS) $(IDIR) -c $<  -DARRAY_LIST

linearsearch.o: linearsearch.c 
	$(CC) $(CFLAGS) $(IDIR) -c $<  -DARRAY_LIST

clean: 
	$(RM) *.o stackarray queuearray linkedlist sortingmain bstmain minheaptreemain searchmain avltreemain
