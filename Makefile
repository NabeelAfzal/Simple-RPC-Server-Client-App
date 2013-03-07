CC = gcc
DEBUG = -g
CFLAGS = -Wall -I$(IDIR) -c
LFLAGS = -Wall -I$(IDIR) -o

IDIR = include
LIBDIR = lib
SRCDIR = src
OBJDIR = obj

LIBFLAGS = -lprotobuf-c

DEPS = task.pb-c.h compare.h
DEP = $(patsubst %,$(IDIR)/%,$(DEPS))

SOURCES = client.c server.c
SRC = $(patsubst %,$(SRCDIR)/%,$(SOURCES))

COMMONSOURCES = task.pb-c.c compare.c
COMSRC = $(patsubst %,$(SRCDIR)/%,$(COMMONSOURCES))
COMMONOBJECTS = $(patsubst %.c,%.o,$(COMMONSOURCES))
COMOBJ = $(patsubst %,$(OBJDIR)/%,$(COMMONOBJECTS))

OBJECTS = $(patsubst %.c,%.o,$(SOURCES))
OBJ = $(patsubst %,$(OBJDIR)/%,$(OBJECTS))

EXECUTABLES = client server

all: $(OBJDIR) $(SRC) $(OBJ) $(COMSRC) $(COMOBJ) $(DEP) $(EXECUTABLES)

$(OBJDIR):
	if [ -d $(OBJDIR) ];then echo "Obj directory exists.";else mkdir $(OBJDIR);fi

%: $(OBJDIR)/%.o $(COMOBJ)
	$(CC) $(LFLAGS) $@ $^ $(LIBFLAGS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(DEP)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJDIR)/*.o *~ $(EXECUTABLES)

