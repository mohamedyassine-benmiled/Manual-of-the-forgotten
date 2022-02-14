########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings - Can be customized.
CC = gcc
CXXFLAGS = -std=c11 -Wall -g
LDFLAGS = -lSDL -lSDL_ttf -lSDL_image

# Makefile settings - Can be customized.
APPNAME = book
EXT = .c
SRCDIR = game
OBJDIR = obj

#INCLUDES = -I /usr/local/include -Ia -Ib -Ic -I ($(HOME)/include -I include

#LIBINCLUDES = -L /usr/local/lib -L build/lib  -L $(HOME)/lib 

#INC = $(INCLUDES) $(LIBINCLUDES) 
############## Do not change anything from here downwards! #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=%.d)
# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)
# Windows OS variables & settings
DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(APPNAME)

# Builds the app
$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

obj/main.o: game/main.c
		gcc -c game/main.c -g
		mv main.o obj/main.o
obj/image.o: game/image.c
		gcc -c game/image.c -g
		mv image.o obj/image.o
obj/text.o: game/text.c
		gcc -c game/text.c -g
		-mkdir obj 
		mv text.o obj/text.o
obj/sound.o: game/sound.c
		gcc -c game/sound.c -g
		mv sound.o obj/sound.o

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -o $@ -c $<

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(DEP) $(APPNAME)
	

# Cleans only all files with the extension .d
.PHONY: cleandep
cleandep:
	$(RM) $(DEP)

#################### Cleaning rules for Windows OS #####################
# Cleans complete project
.PHONY: cleanw
cleanw:
	$(DEL) $(WDELOBJ) $(DEP) $(APPNAME)$(EXE)

# Cleans only all files with the extension .d
.PHONY: cleandepw
cleandepw:
	$(DEL) $(DEP)