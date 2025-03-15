# Simple Makefile
# This uses the BUILD to control the optimisation level
# and names + stores the executable appropriately.

##############
# Build Mode #
##############

BUILD=
BUILDDIR = $(CURDIR)/$(BUILD)


###############################
# Search Directories for code #
###############################

vpath %.c .
INCDIRS = .


######################################
# Explicitly stated input and output #
######################################

EXE = ex2_2_$(BUILD).exe
PROJECT = ex2_2
CFILES = #add any external C files to find.

###################################
# Generated .c, obj and src files #
###################################

CLOCAL = $(wildcard *.c)
CFILES += $(CLOCAL)
OBJS := $(addprefix $(BUILDDIR)/, $(CFILES:.c=.o))
DEPS := $(OBJS:.o=.d)

#####################
# Compiler settings #
#####################

CC = gcc-14
STD = -std=c23
OPT := BUILD
INCLUDES = $(addprefix -I, $(INCDIRS))
ERRORS = -Wall -Werror -Wpedantic

releaseFlags = $(OPT)
debugFlags = -g
BUILDFLAGS = $($(BUILD)Flags)
DEPFLAGS = -MP -MD

##########
# Linker #
##########
LINKS=-lm

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