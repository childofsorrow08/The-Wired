/*
 * Copyright (C) 2026 Child of Sorrow
 *
 * This file is part of TheWired kernel.
 *
 * TheWired kernel is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

#include <files/boot_64.inc>

_start32:
    cli

    movl $_stack_top, %esp

    // todo
    ljmp $GDT64_CODE, $_start64

.code64

_start64:
    movabs $_stack_top, %rsp

    call _main
