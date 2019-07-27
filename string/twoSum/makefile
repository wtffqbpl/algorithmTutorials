############################################################
#
# 		MAKEFILE
#
############################################################

CC := gcc
C_FLAGS := -g -c -o

target := test

src_list := $(wildcard *.c)
obj_list := $(patsubst %.c, %.o, $(src_list))

all: $(target)

$(target): $(obj_list)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(C_FLAGS) $@ $<

.PHONY: clean
clean:
	rm -f $(target) *.o


