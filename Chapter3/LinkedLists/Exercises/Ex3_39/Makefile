# Simple Makefile

##############
# Build Mode #
##############

BUILD=debug
BUILDDIR = $(CURDIR)/$(BUILD)


###############################
# Search Directories for code #
###############################

INCDIRS = . 
SRCDIRS = . 


vpath %.c . $(sort $(dir) $(SRCDIRS))



######################################
# Explicitly stated input and output #
######################################

EXE = list_removeWhereTrue.exe
PROJECT = ex3_39
CEXTRA = #any extra C files to include


###################################
# Generated .c, obj and src files #
###################################

#collect .c files and strip the dirs.
CFILES := $(notdir $(foreach D, $(SRCDIRS), $(wildcard $(D)/*.c)))
CFILES += $(CEXTRA)
OBJS := $(addprefix $(BUILDDIR)/, $(CFILES:.c=.o))
DEPS := $(OBJS:.o=.d)

#####################
# Compiler settings #
#####################

CC = gcc-14
STD = -std=c23
OPT = -O2
INCLUDES = $(addprefix -I, $(INCDIRS))
ERRORS = -Wall -Werror -Wpedantic

releaseFlags = $(OPT)
debugFlags = -g
BUILDFLAGS = $($(BUILD)Flags)
DEPFLAGS = -MP -MD

##########
# Linker #
##########
LINKS=

# put the flags together
CFLAGS = $(STD) $(ERRORS) $(INCLUDES) $(BUILDFLAGS) $(DEPFLAGS)

###########
# RECIPES #
###########

.PHONY: all clean cleanall distribute diff

all: $(BUILDDIR)/$(EXE)

#ensure directory exists
$(BUILDDIR):
	mkdir $(BUILDDIR)

$(BUILDDIR)/$(EXE): $(OBJS) | $(BUILDDIR)
	$(CC) -o $@ $^ $(LINKS)

$(BUILDDIR)/%.o: %.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -rf $(BUILDDIR)/ $(wildcard *.tgz)

cleanall:
	rm -rf ./*/

distribute: cleanall
	tar zcvf $(PROJECT).tgz *

diff:
	$(info The status of the repository and the volume of per-file changes:)
	@git status
	@git diff --stat

-include $(DEPS)