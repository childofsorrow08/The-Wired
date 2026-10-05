ifneq ($(CC_32),)
	CC32 = $(CROSS_CC_32)
else
	ifneq ($(CC_64),)
		CC32 = $(CROSS_CC_64)
	else
		CC32 = gcc
	endif
endif
