#---------

# Makefile


DEBUG= -g

OPTION = -std=c++0x

COMPILER=g++

main : mainPoesie.cc Poesie.o Strophe.o Vers.o
	
	$(COMPILER) $(OPTION) $(DEBUG) -o main mainPoesie.cc Poesie.o Strophe.o Vers.o
	
Vers.o : Vers.cc Vers.h
	
	$(COMPILER) -c $(OPTION) $(DEBUG) Vers.cc
	
Strophe.o : Strophe.cc Strophe.h Vers.h
	
	$(COMPILER) -c $(OPTION) $(DEBUG) Strophe.cc
	
Poesie.o : Poesie.cc Poesie.h Strophe.h Vers.h
	
	$(COMPILER) -c $(OPTION) $(DEBUG) Poesie.cc
	
Code : mainPoesie.cc Vers.h Vers.cc Strophe.h Strophe.cc Poesie.h Poesie.cc
	
	echo "//--------------main" > Code
	
	cat mainPoesie.cc >> Code
	
	echo "//--------------Vers.h" >> Code
	
	cat Vers.h >> Code
	
	echo "//--------------Vers.cc" >> Code
	
	cat Vers.cc >> Code
	
	echo "//--------------Strophe.h" >> Code
	
	cat Strophe.h >> Code
	
	echo "--------------Strophe.cc" >> Code
	
	cat Strophe.cc >> Code
	
	echo "--------------Poesie.h" >> Code
	
	cat Poesie.h >> Code
	
	echo "--------------Poesie.cc" >> Code
	
	cat Poesie.cc >> Code
