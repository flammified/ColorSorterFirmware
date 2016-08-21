#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2015
#
# This file is in the public domain.
# 
#############################################################################

# Specify target chip or board or system
TARGET     := lpc1114fn28

# Specify the location of the bmptk library
BMPTK      := /home/alexander/Documents/Tools/bmptk

SOURCES	   := timer.c pins.c sw-uart.c adc.c colors.c flips.c 1602lcd.c mcp.c i2c.c util.c
HEADERS    := timer.h pins.h sw-uart.h adc.h colors.h flips.h 1602lcd.h mcp.h i2c.h util.h

SEARCH     := /home/alexander/Documents/PrPj/TH04/Libraries

# The Makefile.inc does all the work
include $(BMPTK)/Makefile.inc
