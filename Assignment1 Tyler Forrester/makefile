#Commented Out Testing Code Contains InputValid which validates inputs. 
CXX = g++ 
OBJSSUM = Item.o
SRCSSUM = Item.cpp
OBJSAVG = List.o
SRCSAVG = List.cpp
OBJSL1 = InputValid.o
SRCSL1 = InputValid.cpp
OBJSL2 = Assignment1.o
SRCSL2 = Assignment1.cpp
#OBJSL3 = TestSuite.o
#SRCSL3 = TestSuite.cpp
HEADERS = Item.hpp
HEADERA = List.hpp
HEADERI = InputValid.hpp
PROG = Assignment1
#PROGT = Test

all: $(PROG) 

$(PROG): $(OBJSL2) $(OBJSSUM) $(OBJSAVG) $(OBJSL1)
	$(CXX) $(OBJSAVG) $(OBJSL2) $(OBJSSUM) $(OBJSL1) -o $(PROG)
#$(PROGT): $(OBJSL3) $(OBJSSUM) $(OBJSAVG) $(OBJSL1)
#	$(CXX) $(OBJSAVG) $(OBJSL3) $(OBJSSUM) $(OBJSL1) -o $(PROGT)
$(OBJSL2): $(SRCSL2) $(HEADERS) $(HEADERA) $(HEADERI)
	$(CXX) -c $(SRCSL2)
$(OBJSAVG): $(SCRSAVG) $(HEADERA) 
	$(CXX) -c $(SRCSAVG)
$(OBJSL1): $(SRCSL1) $(HEADERI)
	$(CXX) -c $(SRCSL1)
$(OBJSSUM): $(SRCSSUM) $(HEADERS)
	$(CXX) -c $(SRCSSUM)
#$(OBJSL3): $(SRCSL3) $(HEADERS) $(HEADERA) $(HEADERI)
#	$(CXX) -c $(SRCSL3)
clean:
	rm -rf $(PROG) *.o  *~
