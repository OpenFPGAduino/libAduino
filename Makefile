CFLAGS = -D _DEBUG -static -g  -Wall
CC=arm-none-linux-gnueabi-gcc
AR=arm-none-linux-gnueabi-ar
SRC=$(wildcard api/*.c hardware/*.c ut/*.c)
OBJ=$(addprefix ./, $(addsuffix .o, $(basename $(SRC))))
LIB=libaduino.a
SO =libaduino.so
HEAD=api/openfpgaduino.h

all: $(LIB) $(SO) lib

lib:
	mkdir lib
	cp -f $(LIB) ./lib/
	cp -f $(SO) ./lib/
	cp -f $(HEAD) ./lib/

$(LIB): $(OBJ)
	$(AR) -rcs $@ $^

$(SO): $(OBJ)
	$(CC) -shared -fPCI -o $@ $^
	
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(LIB) $(SO) $(OBJ)
	rm -rf lib

format:
	find . -name "*.c" -exec astyle -n {} \;
	find . -name "*.h" -exec astyle -n {} \;	 	 
