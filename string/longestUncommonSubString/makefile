####################################################################################
#
#			MAKEFILE
#
####################################################################################

CC := gcc
C_FLAGS := -g -c -o

target := test
obj_list := $(patsubst %.c, %.o, $(wildcard *.c))

.PHONY: all
all: clean $(target)

$(target): $(obj_list)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(C_FLAGS) $@ $<

.PHONY: all
clean:
	@rm -rf $(target) $(obj_list)

