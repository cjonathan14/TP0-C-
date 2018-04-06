CXXARGS  = -g -Wall -pedantic -ansi
CXXFLAGS = -I. $(CXXARGS)

all: cmdline.exe
	

cmdline.exe: main.o cmdline.o process_signal.o signal_processing.o Complex.o err.o
	$(CXX) $(CXXFLAGS) -o cmdline.exe cmdline.o main.o process_signal.o signal_processing.o Complex.o err.o
main.o: main.cc main.h types.h process_signal.h err.h 
	$(CXX) $(CXXFLAGS) -c main.cc
cmdline.o: cmdline.cc cmdline.h
	$(CXX) $(CXXFLAGS) -c cmdline.cc
process_signal.o: process_signal.cc process_signal.h signal_processing.h TempArray.h err.h types.h Complex.h
	$(CXX) $(CXXFLAGS) -c process_signal.cc
signal_processing.o: signal_processing.cc signal_processing.h Complex.h err.h TempArray.h types.h
	$(CXX) $(CXXFLAGS) -c signal_processing.cc 
Complex.o: Complex.cc Complex.h 
	$(CXX) $(CXXFLAGS) -c Complex.cc
err.o: err.cc err.h 
	$(CXX) $(CXXFLAGS) -c err.cc 


#runtest.exe: runtest.cc
#	$(CXX) $(CXXFLAGS) -o runtest.exe runtest.cc

#test tests: cmdline.exe runtest.exe
#	runtest.exe cmdline.tests

clean:
	$(RM) -vf *.o *.exe *.t *.out *.err