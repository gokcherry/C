CC      = gcc
CFLAGS  = -Iinclude -Wall -Wextra -std=c99
SRCDIR  = src
OBJDIR  = obj
BINDIR  = bin
TARGET  = uzay_simulasyon.exe  # çalıştırılabilir dosyanızın adı

SRCS    = $(wildcard $(SRCDIR)/*.c) \
          $(wildcard $(SRCDIR)/araclar/*.c) \
          $(wildcard $(SRCDIR)/modeller/*.c) \
          $(wildcard $(SRCDIR)/simulasyon/*.c)
OBJS    = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

all: $(BINDIR) $(OBJDIR) $(TARGET)

$(OBJDIR):
	@mkdir "$(OBJDIR)"

$(BINDIR):
	@mkdir "$(BINDIR)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir "$(dir $@)" 2>nul
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $(BINDIR)/$(TARGET)

.PHONY: clean
clean:
	@if exist "$(OBJDIR)"  ( \
	    echo Removing object directory... & \
	    rmdir /S /Q "$(OBJDIR)" \
	)
	@if exist "$(BINDIR)\$(TARGET)"  ( \
	    echo Removing executable... & \
	    del /Q "$(BINDIR)\$(TARGET)" \
	)
