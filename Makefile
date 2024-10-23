CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude -I/opt/homebrew/opt/openssl@3/include
LDFLAGS = -L/opt/homebrew/opt/openssl@3/lib -lssl -lcrypto

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

SRCS = $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/file_operations.cpp \
       $(SRC_DIR)/crypto_operations.cpp \
       $(SRC_DIR)/hash_operations.cpp
OBJS = $(BUILD_DIR)/main.o \
       $(BUILD_DIR)/file_operations.o \
       $(BUILD_DIR)/crypto_operations.o \
       $(BUILD_DIR)/hash_operations.o

TARGET = project

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)
	rm -f data/*.txt
	rm -f data/*.bin

