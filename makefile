FILES = *.cpp
HEADER_LOCATION = includes
SOURCE_LOCATION = source
BINARY_LOCATION = bin
BINARY_EXECUTABLE = a.out

run: $(BINARY_EXECUTABLE)
	@$(BINARY_LOCATION)/$(BINARY_EXECUTABLE)

all: $(BINARY_EXECUTABLE)

$(BINARY_EXECUTABLE): 
	@g++ -std=c++11 -I $(HEADER_LOCATION) $(SOURCE_LOCATION)/$(FILES) -o $(BINARY_LOCATION)/$(BINARY_EXECUTABLE)

clean: rm -f $(BINARY_LOCATION)/*