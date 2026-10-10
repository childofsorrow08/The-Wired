ifneq ($(CC_32),)
	CC32 = $(CROSS_CC_32)
else ifneq ($(LOCAL_CC_32),)
	CC32 = $(LOCAL_CC_32)
else
	CC32 = gcc
endif
