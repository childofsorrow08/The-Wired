ifneq ($(AS_64),)
	AS64 = $(CROSS_AS_64)
else
	AS64 = as
endif
