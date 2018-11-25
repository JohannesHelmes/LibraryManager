SRC_DIR = src
BIN_DIR = bin
TEST_DIR = test

INC_DIR = include

CPPFLAGS += -I$(INC_DIR)
CFLAGS += -O2
LDFLAGS += -Llib
LDLIBS += -lm

CLASSES = Isbn
OBJ_ALL = $(addprefix $(BIN_DIR)/,$(addsuffix .o,$(CLASSES)))

all : $(OBJ_ALL)

test : $(TEST_DIR)/mainTest

$(BIN_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/%.o : $(TEST_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/mainTest : $(TEST_DIR)/mainTest.o
	$(CXX) $(LDFLAGS) $(LDLIBS) -o $@

clean:
	rm $(BIN_DIR)/Isbn.o

