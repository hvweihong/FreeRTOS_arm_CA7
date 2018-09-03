CC = arm-eabi-gcc
AR = arm-eabi-ar
LD = arm-eabi-ld

TOOL_PATH := ../gcc_tool
TOOL_NAME := gcc-linaro-5.1-2015.08-x86_64_arm-eabi
export PATH:=$(TOOL_PATH)/$(TOOL_NAME)/bin:$(PATH)

CFLAGS += -g -mcpu=cortex-a7 -Wall

APP_DIR := .
KERNEL_DIR := ../kernel
LIBS_DIR := ../libs
OS = $(LIBS_DIR)/FreeRTOS.a
LDSCRIPT = lscript.ld

TARGET = $(APP_DIR)/FreeRTOS.elf

INC += -I. \
-I$(KERNEL_DIR)/include \
-I$(KERNEL_DIR)/portable/ARM_CA9 \
-I$(KERNEL_DIR)/portable/MemMang \

USR_ASM_FILES = $(APP_DIR)/crt0.S \
$(APP_DIR)/FreeRTOS_asm_vectors.S

USR_C_FILES = $(APP_DIR)/FreeRTOS_tick_config.c \
$(APP_DIR)/vectors.c \
$(APP_DIR)/main.c

USR_ASM_OBJS = $(patsubst %.S, %.o, $(USR_ASM_FILES))
USR_C_OBJS = $(patsubst %.c, %.o, $(USR_C_FILES))

all:$(TARGET)

$(TARGET):$(USR_C_OBJS) $(USR_ASM_OBJS) $(OS)
	$(LD) -A cortex-a7 -T $(LDSCRIPT) $(USR_C_OBJS) $(USR_ASM_OBJS) $(OS) \
	$(LIBS_DIR)/libc.a $(LIBS_DIR)/libgcc.a -o $(TARGET) -M > FreeROTS.map

$(USR_ASM_OBJS):%.o:%.S
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

$(USR_C_OBJS):%.o:%.c
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm $(USR_ASM_OBJS) $(USR_C_OBJS) $(TARGET)