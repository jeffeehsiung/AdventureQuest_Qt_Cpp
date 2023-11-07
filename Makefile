TITLE_COLOR = \033[32m
RESET_COLOR = \033[0m

# Compiler to use
CXX = g++

# Qt include paths
QT_INCLUDES = -isystem /usr/include/x86_64-linux-gnu/qt5 \
              -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore \
              -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui \
              -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets

# Flags for compiler
CXXFLAGS = -Wall -std=c++20 -Werror -fdiagnostics-color=auto -fPIC $(QT_INCLUDES)

# Source files directory
SRCS_DIR = source

# Source files
SRCS = $(wildcard $(SRCS_DIR)/*.cpp)

# Object files should have the same directory as the source files
OBJS = $(SRCS:.cpp=.o)

# Header files directory
HDRS_DIR = headers

# Header files
HDRS = $(wildcard $(HDRS_DIR)/*.h)

# Executable name
EXEC = main

# Build rules
all: $(EXEC)

$(EXEC): $(OBJS)
    @echo "$(TITLE_COLOR)***** Compiling and linking all source files *****$(RESET_COLOR)"
    $(CXX) $(CXXFLAGS) -I$(HDRS_DIR) -o $(EXEC) $(OBJS)

# Rule for creating object files from cpp source files
$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(HDRS)
    @echo "$(TITLE_COLOR)***** Compiling $< *****$(RESET_COLOR)"
    $(CXX) $(CXXFLAGS) -I$(HDRS_DIR) -c $< -o $@

run: $(EXEC)
    @echo "$(TITLE_COLOR)***** Running application *****$(RESET_COLOR)"
    ./$(EXEC)

# Cleanup object files, executables
clean:
    @echo "$(TITLE_COLOR)***** Cleaning objects and executable *****$(RESET_COLOR)"
    rm -f $(OBJS) $(EXEC)

.PHONY: all run clean
