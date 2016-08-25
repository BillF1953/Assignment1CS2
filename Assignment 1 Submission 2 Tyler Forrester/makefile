
CXX = g++ 
OBJSSUM = Item.o
SRCSSUM = Item.cpp
OBJSAVG = List.o
SRCSAVG = List.cpp
OBJSL1 = InputValid.o
SRCSL1 = InputValid.cpp
OBJSL2 = Assignment1Main.o
SRCSL2 = Assignment1Main.cpp
HEADERS = Item.hpp
HEADERA = List.hpp
HEADERI = InputValid.hpp
PROG = Assignment1
#PROGT = Test

all: $(PROG) 

$(PROG): $(OBJSL2) $(OBJSSUM) $(OBJSAVG) $(OBJSL1)
	$(CXX) $(OBJSAVG) $(OBJSL2) $(OBJSSUM) $(OBJSL1) -o $(PROG)
$(OBJSL2): $(SRCSL2) $(HEADERS) $(HEADERA) $(HEADERI)
	$(CXX) -c $(SRCSL2)
$(OBJSAVG): $(SCRSAVG) $(HEADERA) 
	$(CXX) -c $(SRCSAVG)
$(OBJSL1): $(SRCSL1) $(HEADERI)
	$(CXX) -c $(SRCSL1)
$(OBJSSUM): $(SRCSSUM) $(HEADERS)
	$(CXX) -c $(SRCSSUM)
clean:
	rm -rf $(PROG) *.o  *~
