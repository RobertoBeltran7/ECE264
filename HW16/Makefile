WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose --track-origins=yes

TESTFALGS = -DTEST_MAIN -DTEST_FREETREE -DTEST_SEARCH -DTEST_SUBTREE -DTEST_CONTAINED -DPRINT_FUN

SRCS = hw16.c main.c binarytree.c
OBJS = $(SRCS:%.c=%.o)

hw16: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw16

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: hw16
	$(VAL) ./hw16 testcases/inputs/tree1/test1.txt testcases/inputs/tree2/test1.txt > output1.txt
	$(VAL) ./hw16 testcases/inputs/tree1/test2.txt testcases/inputs/tree2/test2.txt > output2.txt
	$(VAL) ./hw16 testcases/inputs/tree1/test3.txt testcases/inputs/tree2/test3.txt > output3.txt
	$(VAL) ./hw16 testcases/inputs/tree1/test4.txt testcases/inputs/tree2/test4.txt > output4.txt
	$(VAL) ./hw16 testcases/inputs/tree1/test5.txt testcases/inputs/tree2/test5.txt > output5.txt
	$(VAL) ./hw16 testcases/inputs/tree1/test6.txt testcases/inputs/tree2/test6.txt > output6.txt
	$(VAL) ./hw16 testcases/inputs/tree1/test7.txt testcases/inputs/tree2/test7.txt > output7.txt
	$(VAL) ./hw16 testcases/inputs/tree1/test8.txt testcases/inputs/tree2/test8.txt > output8.txt


testall: test1 test2 test3 test4 test5 test6

testadd: hw16 # hw16 here to ensure recompilation if necessary
	test1
	test2
	test3
	test4
	test5
	test6
	test7
	test8

test1: hw16
	./hw16 testcases/inputs/tree1/test1.txt testcases/inputs/tree2/test1.txt > output1.txt
	diff -i -w output1.txt testcases/expected/expected1.txt
test2: hw16
	./hw16 testcases/inputs/tree1/test2.txt testcases/inputs/tree2/test2.txt > output2.txt
	diff -i -w output2.txt testcases/expected/expected2.txt
test3: hw16
	./hw16 testcases/inputs/tree1/test3.txt testcases/inputs/tree2/test3.txt > output3.txt
	diff -i -w output3.txt testcases/expected/expected3.txt
test4: hw16
	./hw16 testcases/inputs/tree1/test4.txt testcases/inputs/tree2/test4.txt > output4.txt
	diff -i -w output4.txt testcases/expected/expected4.txt
test5: hw16
	./hw16 testcases/inputs/tree1/test5.txt testcases/inputs/tree2/test5.txt > output5.txt
	diff -i -w output5.txt testcases/expected/expected5.txt
test6: hw16
	./hw16 testcases/inputs/tree1/test6.txt testcases/inputs/tree2/test6.txt > output6.txt
	diff -i -w output6.txt testcases/expected/expected6.txt
test7: hw16
	./hw16 testcases/inputs/tree1/test7.txt testcases/inputs/tree2/test7.txt > output7.txt
	diff -i -w output7.txt testcases/expected/expected7.txt
test8: hw16
	./hw16 testcases/inputs/tree1/test8.txt testcases/inputs/tree2/test8.txt > output8.txt
	diff -i -w output8.txt testcases/expected/expected8.txt


clean: # remove all machine generated files
	rm -f hw16 *.o 
