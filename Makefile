SRC_DIR = src
BIN_DIR = bin
TEST_DIR = test

INC_DIR = include

CPPFLAGS += -I$(INC_DIR)
CFLAGS += -O2
LDFLAGS += -Llib
LDLIBS += -lm


SRC_APP = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_APP = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRC_APP))

TEST = $(TEST_DIR)/TestLibraryManager
SRC_TEST = $(wildcard $(TEST_DIR)/*.cpp)
OBJ_TEST = $(patsubst $(TEST_DIR)/%.cpp,$(TEST_DIR)/%.o,$(SRC_TEST))


all : $(OBJ_APP)

test : $(TEST)

$(TEST) : $(OBJ_TEST) $(OBJ_APP)
	$(CXX) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(BIN_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/%.o : $(TEST_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJ_TEST) $(OBJ_APP) $(TEST)

