TARGET=main
OBJS = sum.o
CC = g++
INCLUDE_DIR=include
SRC_DIR=src
BUILD_DIR=build
CFLAGS=-I$(INCLUDE_DIR) -O2 -o


main: $(OBJS) $(SRC_DIR)/main.c
	$(CC) $(BUILD_DIR)/*.o $(SRC_DIR)/main.c $(CFLAGS) $(BUILD_DIR)/$(TARGET)

sum.o: $(SRC_DIR)/sum.c
	$(CC) -c $(SRC_DIR)/sum.c $(CFLAGS) $(BUILD_DIR)/sum.o


.PHONY : clean
clean :
	rm -rf $(BUILD_DIR)/*


