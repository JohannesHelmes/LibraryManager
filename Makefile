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

TEST = $(TEST_DIR)/testLibraryManager
TEST_SRC = testIsbn mainTest
TEST_OBJ= $(addprefix $(TEST_DIR)/,$(addsuffix .o,$(TEST_SRC)))

all : $(OBJ_ALL)

test : $(TEST)

$(TEST) : $(TEST_OBJ) $(OBJ_ALL)
	$(CXX) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(BIN_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/%.o : $(TEST_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


clean:
	$(RM) $(BIN_DIR)/Isbn.o $(TEST_DIR)/mainTest

