WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose --track-origins=yes

TESTFALGS = -DTEST_READHEADER -DTEST_DECODE -DTEST_MERGELIST -DDO_NOT_MODIFY 

SRCS = decode.c list.c main.c tree.c utility.c 
OBJS = $(SRCS:%.c=%.o)

hw20: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw20

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: hw20
	$(VAL) ./hw20 input/input1.bin output1.txt
	$(VAL) ./hw20 input/input2.bin output2.txt
	$(VAL) ./hw20 input/input3.bin output3.txt
	$(VAL) ./hw20 input/input4.bin output4.txt
	$(VAL) ./hw20 input/input5.bin output5.txt
	$(VAL) ./hw20 input/input6.bin output6.txt
	$(VAL) ./hw20 input/input7.bin output7.txt
	$(VAL) ./hw20 input/input8.bin output8.txt


testall: test1 test2 test3 test4 test5 test6 test7 test8

testadd: hw20 # hw20 here to ensure recompilation if necessary
	test1
	test2
	test3
	test4
	test5
	test6
	test7
	test8

test1: hw20
	./hw20 input/input1.bin output1.txt
	diff -i -w output1.txt expected/expected1.txt
test2: hw20
	./hw20 input/input2.bin output2.txt
	diff -i -w output2.txt expected/expected2.txt
test3: hw20
	./hw20 input/input3.bin output3.txt
	diff -i -w output3.txt expected/expected3.txt
test4: hw20
	./hw20 input/input4.bin output4.txt
	diff -i -w output4.txt expected/expected4.txt
test5: hw20
	./hw20 input/input5.bin output5.txt
	diff -i -w output5.txt expected/expected5.txt
test6: hw20
	./hw20 input/input6.bin output6.txt
	diff -i -w output6.txt expected/expected6.txt
test7: hw20
	./hw20 input/input7.bin output7.txt
	diff -i -w output7.txt expected/expected7.txt
test8: hw20
	./hw20 input/input8.bin output8.txt
	diff -i -w output8.txt expected/expected8.txt

clean: # remove all machine generated files
	rm -f hw20 *.o 
