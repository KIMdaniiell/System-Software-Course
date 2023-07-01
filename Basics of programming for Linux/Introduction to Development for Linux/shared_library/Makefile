.PHONY: run clean
BUILD_DIR = build
SOURCE_DIR = source

# Компиляция исполняемого файла с учетом разделяемой библиотеки
$(BUILD_DIR)/main: $(SOURCE_DIR)/main.c $(SOURCE_DIR)/hello.h $(BUILD_DIR)/libhello.so
	gcc $(SOURCE_DIR)/main.c -L./$(BUILD_DIR) -lhello -o $(BUILD_DIR)/main
		# Ключ L - дирректория, содержащая скомпилированную разделяемую библиотеку
		# Ключ l - наименование разделяемой библиотеки

# Компиляция разделяемой библиотеки
$(BUILD_DIR)/libhello.so: $(SOURCE_DIR)/hello.c $(SOURCE_DIR)/hello.h
	gcc $(SOURCE_DIR)/hello.c -shared -o $(BUILD_DIR)/libhello.so -fPIC
	

run: $(BUILD_DIR)/main $(BUILD_DIR)/libhello.so
	printenv | grep LD_LIBRARY_PATH
		# При запуске программы использующей разделяемую библиотеку,
		# линковщику необходимо знать путь до этой библиотеки.
		# Для этого задаётся переменная окружение - LD_LIBRARY_PATH
		#
		# P.s. кажется назначить значение переменной окружения из Makefile
		# нельзя, поэтому я тут просто использую вывод значения этой переменной 
		# с помощью printenv, чтобы видеть ее текущее значение
	./$(BUILD_DIR)/main

clean:
	rm $(BUILD_DIR)/*
