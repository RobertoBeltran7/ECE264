WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_SPLIT -DTEST_MERGE -DTEST_SORT -DLINKEDLIST

SRCS = hw14.c main.c
OBJS = $(SRCS:%.c=%.o)

hw13: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw14

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: hw14
	$(VAL) ./hw14 inputs/test1.txt > output1.txt

testall: test1 test2 test3 test4

testadd: hw14 # hw14 here to ensure recompilation if necessary
	test1
	test2


test1: hw14
	./hw14 inputs/test1.txt > output1.txt
	diff output1.txt expected/expected1.txt

test2: hw14
	./hw14 inputs/test2.txt > output2.txt
	diff output2.txt expected/expected2.txt

clean: # remove all machine generated files
	rm -f hw14 *.o 
