PROG=scanKey
SRCS=scanKey.c
OBJS=$(SRCS:%.c=%.c.o)
LDFLAGS=-lcurses

all: $(PROG)

$(PROG): $(OBJS)
	$(LINK.o) $(OUTPUT_OPTION) $^

%.c.o: %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

run: $(PROG)
	./$<

.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJS)
