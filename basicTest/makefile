###################################################################
#
#					MAKEFILE
#
###################################################################

CC := gcc
CFLAGS := -g -c -o

target := test
obj_dir := obj
obj_list := $(addprefix $(obj_dir)/, $(patsubst %c, %o, $(wildcard *.c)))


.PHONY: all prebuild clean
all: clean prebuild $(target)
	@echo $(obj_list)

prebuild:
	@if test ! -d "$(obj_dir)"; then mkdir -p $(obj_dir); fi

$(target): $(obj_list)
	$(CC) -o $@ $^

$(obj_dir)/%.o: %.c
	$(CC) $(CFLAGS) $@ $<

clean:
	@rm -rf $(target) $(obj_dir)
