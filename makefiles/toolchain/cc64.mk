ifneq ($(CC_64),)
	CC64 = $(CROSS_CC_64)
else ifneq ($(LOCAL_CC_64),)
	CC64 = $(LOCAL_CC_64)
else
	CC64 = gcc
endif
