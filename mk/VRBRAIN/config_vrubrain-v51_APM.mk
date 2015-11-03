#
# Makefile for the VR MICRO BRAIN 5.1 APM configuration
#
include $(SKETCHBOOK)/mk/VRBRAIN/vrbrain_common.mk

#
# Use the configuration's ROMFS.
#
ROMFS_ROOT	 = $(SKETCHBOOK)/mk/VRBRAIN/ROMFS_VRBRAIN_APM








MODULES		+= drivers/stm32/tone_alarm





























MODULES		+= drivers/pwm_input


MODULES		+= drivers/boards/vrubrain-v51










































































































































