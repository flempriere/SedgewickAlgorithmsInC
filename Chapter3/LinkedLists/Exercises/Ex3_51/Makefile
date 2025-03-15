# Simple Makefile

##############
# Build Mode #
##############



BUILD=debug
#use program3_14_interface for old interface
#use ex3_50_interface for new interface
INTERFACE=program3_14_interface
BUILDDIR=$(CURDIR)/$(BUILD)/$(INTERFACE)


###############################
# Search Directories for code #
###############################

INCDIRS.program3_14_interface := ../../Examples/Program3_12-14_ListImplementation 
SRCDIRS.program3_14_interface := ../../Examples/Program3_12-14_ListImplementation

INCDIRS.ex3_50_interface := ../Ex3_50
SRCDIRS.ex3_50_interface := ../Ex3_50

INCDIRS := . $(INCDIRS.$(INTERFACE))
SRCDIRS := . $(SRCDIRS.$(INTERFACE))


vpath %.c . $(sort $(dir) $(SRCDIRS))



######################################
# Explicitly stated input and output #
######################################

EXE = ListWithFree.exe
PROJECT = ex3_47
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
CPPFLAGS.program3_14_interface := -UUSE_V2_INTERFACE
CPPFLAGS.ex3_50_interface := -DUSE_V2_INTERFACE
CPPFLAGS := $(CPPFLAGS.$(INTERFACE))

##########
# Linker #
##########
LINKS=

# put the flags together
CFLAGS = $(STD) $(ERRORS) $(INCLUDES) $(CPPFLAGS) $(BUILDFLAGS) $(DEPFLAGS)

###########
# RECIPES #
###########

.PHONY: all clean cleanall distribute diff

all: $(BUILDDIR)/$(EXE)

#ensure directory exists
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

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