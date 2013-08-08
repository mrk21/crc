MAKEFILE := $(word $(words $(MAKEFILE_LIST)), $(MAKEFILE_LIST))
MAKEFILE_DIR := $(dir $(MAKEFILE))
ENV ?= target
include $(MAKEFILE_DIR)/crc/$(ENV).mk

INCLUDE_DIRS += -I$(ROOT_DIR)/inc -I$(ROOT_DIR)/src
