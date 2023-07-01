.PHONY: all run clean
BUILD_DIR = build
SOURCE_DIR = source

all: $(BUILD_DIR)/libhello.so $(BUILD_DIR)/exe

$(BUILD_DIR)/exe: $(SOURCE_DIR)/main.c 
	gcc $(SOURCE_DIR)/main.c -ldl -o $(BUILD_DIR)/exe

$(BUILD_DIR)/libhello.so: $(SOURCE_DIR)/hello.c $(SOURCE_DIR)/hello.h
	gcc $(SOURCE_DIR)/hello.c -shared -o $(BUILD_DIR)/libhello.so 
	
run: $(BUILD_DIR)/exe $(BUILD_DIR)/libhello.so
	./$(BUILD_DIR)/exe
		# Т.к. файл libhello.so находится в поддиректории build, а в main.c его поиск
		# осуществляется в текущем каталоге, библиотека не будет найдена.
		#
		# Для успешного выполения нужно или скопировать файл libhello.so в текущий
		# каталог, или в main.c поменять путь к файлу

clean:
	rm $(BUILD_DIR)/* 2>/dev/null
