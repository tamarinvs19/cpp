CXX = g++
CXXFLAGS = -O2 -Wall -Werror -std=c++17 -Iinclude
LDFLAGS = 

EXE = hw_03
SRCDIR = src
EXE_TEST = hw_03_test
TEST_DIR = test
OBJDIR = obj

OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(wildcard $(SRCDIR)/*.cpp))
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.cpp,$(OBJDIR)/%.o,$(wildcard $(TEST_DIR)/*.cpp))

all: $(EXE)

test: $(EXE_TEST)

$(EXE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXE) $(LDFLAGS)
	
$(EXE_TEST): $(TEST_OBJECTS)
	$(CXX) $(TEST_DIR)/test_main.cpp -o $(EXE_TEST) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp, $(TEST_DIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -MMD -o $@ $<

include $(wildcard $(OBJDIR)/*.d)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(EXE) $(EXE_TEST)

.PHONY: clean all
