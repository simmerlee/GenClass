genclass : genclass.o
	g++ -o genclass genclass.o
genclass.o : genclass.cpp
	g++ -c -o genclass.o genclass.cpp
.PHONY : clean
clean :
	rm -f genclass.o genclass
