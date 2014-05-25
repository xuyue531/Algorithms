CC = g++
TARGET = quick_sort.bin
	OBJ = main.o common.o quick_sort.o
$(TARGET):$(OBJ)
	$(CC) -o $(TARGET) $^  -g
main.o:main.cpp
	$(CC) -c main.cpp -g
common.o:common.cpp common.h
	$(CC) -c common.cpp -g
quick_sort.o:quick_sort.cpp quick_sort.h
	$(CC) -c quick_sort.cpp -g

.PHONY: clean
clean:
	rm *.bin *.o *.log 




