################################################################
#
#					MAKEFILE
#
################################################################

CC := gcc
CFLAGS := -g -c -o 

target := jumpGameDemo
obj_dir := obj
obj_list := $(addprefix $(obj_dir)/, $(patsubst %.c, %.o, $(wildcard *.c)))

.PHONY: all
all: clean prebuild $(target)
	@echo $(obj_list)

prebuild:
	@if test ! -d "$(obj_dir)"; then mkdir $(obj_dir); fi

$(target): $(obj_list)
	$(CC) -o $@ $^

$(obj_dir)/%.o: %.c
	$(CC) $(CFLAGS) $@ $<

.PHONY: clean
clean:
	@rm -rf $(obj_dir) $(target)
