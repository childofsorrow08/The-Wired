ifneq ($(AS_32),)
	AS32 = $(CROSS_AS_32)
else ifneq ($(LOCAL_AS_32),)
	AS32 = $(LOCAL_AS_32)
else
	AS32 = as
endif
