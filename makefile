#makefile to build, clean and run a project

DEP_HEADER =  main.h file_scanner.h

%.o: %.c $(DEP_HEADER)
	gcc -c -o $@ $<

build: main.o file_scanner.o
	gcc -g -o run.out main.o file_scanner.o -pthread
	rm *.o
clean: 
	rm *log *out

run:
	./run.out ${args}

usage: 
	@echo "make <enter> (is to build a project) \n"
	@echo "make clean <enter> (is to clean all logs and executables) \n"
	@echo "make args=\"path\" run <enter> (to run the project) \n"


