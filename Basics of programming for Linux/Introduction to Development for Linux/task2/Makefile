.PHONY: run clean

BUILD_DIR = ./build
SOURCE_DIR = ./source

$(BUILD_DIR)/exe: $(SOURCE_DIR)/solution.c
	gcc $(SOURCE_DIR)/solution.c -ldl -o $(BUILD_DIR)/exe

$(BUILD_DIR)/lib: $(SOURCE_DIR)/hello.c $(SOURCE_DIR)/hello.h
	gcc $(SOURCE_DIR)/hello.c $(SOURCE_DIR)/hello.h -shared -o $(BUILD_DIR)/libhello.so

run: $(BUILD_DIR)/exe $(BUILD_DIR)/lib
	./$(BUILD_DIR)/exe  $(BUILD_DIR)/libhello.so hello 3 

clean: 
	rm -r $(BUILD_DIR)/* 2>/dev/null

