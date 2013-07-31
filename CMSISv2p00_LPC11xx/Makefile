include ../config.mk


INCLUDE_DIRS = -Iinc
TARGET = liblpc11xx
FILES = $(call find, ., c)


.DEFAULT: all
.PHONY: all
all: $(TARGET).a

.PHONY: clean
clean:
	$(RM) $(TARGET).* $(call gens, $(FILES))

.PHONY: rebuild
rebuild: clean all


$(TARGET).a: $(call objects, $(FILES))
	$(AR) -r $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $(call dflags, $@) -o $@ $<


-include $(call depends, $(FILES))
