help:
	@echo "make help"
	@echo "make all"

all: AVL_tree.c ADT_llist.c main_tree.c 
	g++ -o main_tree AVL_tree.c ADT_llist.c  main_tree.c -pg

run: all
	./main_tree
	gprof main_tree gmon.out > profile_tree.txt

clean:
	rm *.o *.out profile_tree.txt


