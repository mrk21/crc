include config.mk


CMSIS_DIR = CMSISv2p00_LPC11xx
INCLUDE_DIRS = -I$(CMSIS_DIR)/inc -Iinc -I.
LIB_DIRS = -L$(CMSIS_DIR)
LIBS = -llpc11xx
LD_SCRIPT = lpc1114fn28.ld

TARGET = gen/crc
FILES = $(addprefix gen/, $(call find, src, c) $(call find, src, cpp))

.DEFAULT: all
.SECONDARY: $(call objects, $(FILES)) $(TARGET).elf


.PHONY: all
all: $(TARGET).hex size

.PHONY: size
size: $(TARGET).elf
	$(SIZE) $<

.PHONY: nm
nm: $(TARGET).elf
	$(NM) $<

.PHONY: readelf
readelf: $(call objects, $(FILES)) $(TARGET).elf
	@$(foreach f, $^, \
		echo; \
		echo '#' $(f); \
		echo; \
		readelf -S $(f); \
	)

.PHONY: clean
clean:
	$(RM) -r gen

.PHONY: rebuild
rebuild: clean all

.PHONY: program
program: all
	$(LPC21ISP) -control $(TARGET).hex /dev/ttyUSB0 115200 12000

.PHONY: count
count:
	$(call count, src)


%.hex: %.elf
	$(OBJCOPY) -O ihex $< $@

%.elf: $(LD_SCRIPT) $(call objects, $(FILES))
	$(MAKE) -C $(CMSIS_DIR)
	$(CXX) $(LDFLAGS) $(call linkflags, $@) -o $@ $(wordlist 2, $(words $^), $^) $(LIBS)

gen/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $(call dflags, $@) -o $@ $<

gen/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $(call dflags, $@) -o $@ $<


-include $(call depends, $(FILES))
