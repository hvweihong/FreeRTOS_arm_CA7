CC = arm-eabi-gcc
AR = arm-eabi-ar
LD = arm-eabi-ld

TOOL_PATH := ../gcc_tool
TOOL_NAME := gcc-linaro-5.1-2015.08-x86_64_arm-eabi
export PATH:=$(TOOL_PATH)/$(TOOL_NAME)/bin:$(PATH)

CFLAGS += -g -mcpu=cortex-a7 -Wall

KERNEL_DIR := .
LIBS_DIR := ../libs

OS = $(LIBS_DIR)/FreeRTOS.a
INC += -I. \
-I$(KERNEL_DIR)/include \
-I$(KERNEL_DIR)/../APP \
-I$(KERNEL_DIR)/portable/ARM_CA9 \
-I$(KERNEL_DIR)/portable/MemMang \

OS_ASM_FILES = $(KERNEL_DIR)/portable/ARM_CA9/portASM.S

OS_C_FILES = $(KERNEL_DIR)/croutine.c \
$(KERNEL_DIR)/event_groups.c \
$(KERNEL_DIR)/list.c \
$(KERNEL_DIR)/queue.c \
$(KERNEL_DIR)/stream_buffer.c \
$(KERNEL_DIR)/tasks.c \
$(KERNEL_DIR)/timers.c \
$(KERNEL_DIR)/portable/ARM_CA9/port.c \
$(KERNEL_DIR)/portable/MemMang/heap_2.c

OS_ASM_OBJS = $(patsubst %.S, %.o, $(OS_ASM_FILES))
OS_C_OBJS = $(patsubst %.c, %.o, $(OS_C_FILES))

OS:$(OS)

$(OS):$(OS_C_OBJS) $(OS_ASM_OBJS)
	$(AR) -r $(OS) $(OS_C_OBJS) $(OS_ASM_OBJS)

$(OS_ASM_OBJS):%.o:%.S
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

$(OS_C_OBJS):%.o:%.c
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm $(OS_ASM_OBJS) $(OS_C_OBJS) $(OS)