TITLE_COLOR = \033[32m
RESET_COLOR = \033[0m

# Compiler to use
CXX = g++

# Flags for compiler
CXXFLAGS = -Wall -std=c++20 -Werror -fdiagnostics-color=auto

# Source files
SRCS = $(wildcard *.cpp)

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HDRS = $(wildcard headers/*.h)

# Executable name
EXEC = main

# Build rules
# from all cpp files, create object files and link into executable
$(EXEC): $(OBJS)
	@echo "$(TITLE_COLOR)\n***** compiling and linking all source files *****$(RESET_COLOR)"
	$(CXX) $(CXXFLAGS) $(SRCS) -Iheaders -o $(EXEC)

# Rule for creating object files from cpp source files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(EXEC)

run: $(EXEC)
	@echo "$(TITLE_COLOR)\n***** Running application *****$(RESET_COLOR)"
	./$(EXEC)

# Cleanup object files, executables
clean:
	rm -f $(OBJS) $(EXEC)
