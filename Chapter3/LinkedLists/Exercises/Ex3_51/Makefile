# A Simple Makefile
# Template VERSION = 1.0.0
# Date generated on: 2025-03-23

##############
# BUILD Mode #
##############

BUILD ?= debug
VALID_BUILDS := debug release
$(if $(filter $(BUILD), $(VALID_BUILDS)),,$(error Invalid BUILD option: $(BUILD)))

BUILDDIR = $(CURDIR)/$(BUILD)

USE_V2_INTERFACE ?= 0
VALID_INTERFACE := 0 1
$(if $(filter $(USE_V2_INTERFACE), $(VALID_INTERFACE)),, $(error Invalid interface option: $(INTERFACE)))

LIB_DIR_0 = ../../Examples/Program3_12-14_ListImplementation
LIB_DIR_1 = ../Ex3_47
LIB_DIR = $(LIB_DIR_$(USE_V2_INTERFACE))

DEFINE_0 := -U USE_V2_INTERFACE
DEFINE_1 := -D USE_V2_INTERFACE
DEFINE = $(DEFINE_$(USE_V2_INTERFACE))


###############################
# Search Directories for Code #
###############################

INCLUDE_DIRS = . ./includes $(LIB_DIR)
SOURCE_DIRS = . ./src $(LIB_DIR)
SOURCE_VPATHS = 

vpath %.c $(sort $(dir) $(SOURCE_DIRS) $(SOURCE_VPATHS))


######################################
# Explicitly stated Input and Output #
######################################

EXE = ex3_51.exe
PROJECT = ex3_51
#Any .c files to be included, without including their whole directory
# should not include their directory.
# Their directory must be put in the .c vpath variable.
CEXTRA =  

###################################
# Generated .c, obj and src files #
###################################

# Collect the .c files and strip the dirs.
# We use vpath to locate them.
CFILES := $(notdir $(foreach D, $(SOURCE_DIRS), $(wildcard $(D)/*.c)))
CFILES += $(notdir $(CEXTRA))
OBJS := $(addprefix $(BUILDDIR)/, $(CFILES:.c=.o))
DEPS := $(OBJS:.o=.d)

#####################
# Compiler Settings #
#####################

# Compiler and Standard
CC = gcc-14
STD = -std=c23

#paths for header inclusions
INCLUDES = $(addprefix -I, $(INCLUDE_DIRS))

# Optimisation level for a given build
OPT_debug = -O
OPT_release = -O2

# Flags for warning, memory sanitiser
FLAGS_warning = -Wall -Werror -Wextra -Wpedantic -Wno-unused-parameter        -Wconversion
FLAGS_address = -fsanitize=address,undefined

#dependency generation
FLAGS_dependencies = -MP -MD

# Build Mode flags
FLAGS_release = -g -march=native
FLAGS_debug = -g3

#Linker
FLAGS_linker = 

# Select the flags
BUILDFLAGS = $(FLAGS_$(BUILD))
BUILDFLAGS += $(OPT_$(BUILD))

CFLAGS = $(STD) $(FLAGS_warning) $(FLAGS_address) $(INCLUDES) $(DEFINE) $(BUILDFLAGS) $(FLAGS_dependencies)

###########
# Recipes #
###########

.PHONY: all clean distribute diff

all: $(BUILDDIR)/$(EXE)

#ensure directory exists
$(BUILDDIR):
	mkdir $(BUILDDIR)

$(BUILDDIR)/$(EXE): $(OBJS) | $(BUILDDIR)
	$(CC) $(FLAGS_address) -o $@ $^ $(FLAGS_linker)

$(BUILDDIR)/%.o : %.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILDDIR)/ $(wildcard *tgz)

cleanall:
	rm -rf $(VALID_BUILDS)

distribute: cleanall
	tar zcvf $(PROJECT).tgz *

diff:
	$(info The status of the repository and the volume of per-file changes:)
	@git status
	@git diff --stat

-include $(DEPS)