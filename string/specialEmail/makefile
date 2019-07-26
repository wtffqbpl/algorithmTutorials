##################################################################
#
#		MAKEFILE
#
##################################################################

CC := gcc
C_FLAGS := -g -c -o

target := test
obj_list := $(patsubst %.c, %.o, $(wildcard *.c))

.PHONY: all
all: clean $(target)
	@echo $(obj_list)


$(target): $(obj_list)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(C_FLAGS) $@ $<

.PHONY: clean
clean:
	@rm -rf $(target) *.o


