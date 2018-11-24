SRC_DIR = src
BIN_DIR = bin

INC_DIR = include

CPPFLAGS += -I$(INC_DIR)
CFLAGS += -O2

all : $(BIN_DIR)/Isbn.o

$(BIN_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm $(BIN_DIR)/Isbn.o

