###############################################################
#
#    MAKEFILE
#
###############################################################

CC := g++
CXXFLAGS := -std=c++11 -Wall -g
target := algorithmDemo


vpath .

file_list := $(wildcard *.cc)
build_path := build
obj_list := $(addprefix $(build_path)/, $(patsubst %.cc, %.o, $(file_list)))

all: prebuild $(target)

$(target): $(obj_list)
	@echo $(file_list)
	@echo $(obj_list)
	$(CC) $^ -o $(build_path)/$@

.PHONY: prebuild
prebuild:
	@if test ! -d "$(build_path)"; then mkdir -p $(build_path); fi

$(build_path)/%.o: %.c
	$(CC) $(CXXFLAGS) -o $(build_path)/$@ $<

.PHONY: clean
clean:
	rm -rf *.o $(target) $(build_path)

