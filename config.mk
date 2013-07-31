TOOLCHAIN = arm-none-eabi-
CC      = $(TOOLCHAIN)gcc
CXX     = $(TOOLCHAIN)g++
LD      = $(TOOLCHAIN)ld
AS      = $(TOOLCHAIN)as
OBJCOPY = $(TOOLCHAIN)objcopy
OBJDUMP = $(TOOLCHAIN)objdump
AR      = $(TOOLCHAIN)ar
SIZE    = $(TOOLCHAIN)size
NM      = $(TOOLCHAIN)nm

LPC21ISP = lpc21isp


CFLAGS  = -mcpu=cortex-m0
CFLAGS += -mthumb
CFLAGS += -fmessage-length=0
CFLAGS += -fno-builtin
CFLAGS += -ffunction-sections
CFLAGS += -fdata-sections
CFLAGS += -Os -g3 -Wall
CFLAGS += $(DEFINE)
CFLAGS += $(INCLUDE_DIRS)

CXXFLAGS  = -std=c++11
CXXFLAGS += -fno-rtti
CXXFLAGS += -fno-exceptions
CXXFLAGS += -fno-threadsafe-statics
CXXFLAGS += $(CFLAGS)

# $(call dflags, $filepath)
define dflags
 -MMD -MP -MF"$(basename $1).d" -MT"$(basename $1).o"
endef


LDFLAGS  = -mcpu=cortex-m0 -mthumb
LDFLAGS += -T$(LD_SCRIPT)
LDFLAGS += $(LIB_DIRS)

# $(call mapflags, $filepath)
define linkflags
 -Xlinker --gc-sections -Xlinker -Map="$(basename $1).map"
endef


# $(call find, $target, $ext[, $expr])
define find
 $(shell find $1 -name '*.$(strip $2)' -not -name '.*' $3 | sed -e 's/.$(strip $2)$$//')
endef

# $(call count, $target)
define count
 find $1 -name "*.c" -not -name ".*" -or -name "*.cpp" -not -name ".*" -or -name "*.h" -not -name ".*" -or -name "*.hpp" -not -name ".*" | xargs wc -l
endef



# $(call objects, $files)
define objects
 $(addsuffix .o, $1)
endef

# $(call depends, $files)
define depends
 $(addsuffix .d, $1)
endef

# $(call gens, $files)
define gens
 $(call objects, $1) $(call depends, $1)
endef
