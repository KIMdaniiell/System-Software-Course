.PHONY: run clean
BUILD_DIR = build
SOURCE_DIR = source


$(BUILD_DIR)/main: $(SOURCE_DIR)/main.c $(BUILD_DIR)/libhello.so
	gcc $(SOURCE_DIR)/main.c -L./$(BUILD_DIR) -lhello -o $(BUILD_DIR)/main

$(BUILD_DIR)/libhello.so: $(SOURCE_DIR)/hello.c $(SOURCE_DIR)/hello.h
	gcc $(SOURCE_DIR)/hello.c -shared -o $(BUILD_DIR)/libhello.so -fPIC

run: $(BUILD_DIR)/main $(BUILD_DIR)/libhello.so
	printenv | grep LD_LIBRARY_PATH
	./$(BUILD_DIR)/main

clean:
	rm $(BUILD_DIR)/*
