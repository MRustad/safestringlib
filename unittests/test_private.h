/*------------------------------------------------------------------
 * test_private.h - Internal test routines & library references
 *
 * 2012, Jonathan Toppins <jtoppins@users.sourceforge.net>
 *
 * Copyright (c) 2012, 2013 by Cisco Systems, Inc
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *------------------------------------------------------------------
 */

#ifndef __TEST_PRIVATE_H__
#define __TEST_PRIVATE_H__

#ifdef __KERNEL__

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ctype.h>

#include <linux/string.h>
#define printf(...) printk(KERN_INFO __VA_ARGS__)

#else

#define _GNU_SOURCE 1 /* needed to define strcasestr */
#include <stdio.h>
#include <string.h>

#endif

#ifdef DEBUG
#  ifdef __KERNEL__
#    define debug_printf(...)  printk(KERN_DEBUG __VA_ARGS__)
#  else
#    define debug_printf printf
#  endif
#else
#define debug_printf(...)
#endif

#endif /* __TEST_PRIVATE_H__ */
