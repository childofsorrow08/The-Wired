ifneq ($(AS_32),)
	AS32 = $(CROSS_AS_32)
else
	ifneq ($(AS_64),)
		AS32 = $(CROSS_AS_64)
	else
		AS32 = as
	endif
endif
