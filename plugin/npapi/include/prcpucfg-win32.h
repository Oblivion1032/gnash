// 
//   Copyright (C) 2005, 2006, 2007, 2008, 2009, 2010 Free Software
//   Foundation, Inc
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//

#ifndef nspr_cpucfg___
#define nspr_cpucfg___

#ifndef XP_PC
#define XP_PC
#endif

#ifndef WIN32
#define WIN32
#endif

#ifndef WINNT
#define WINNT
#endif

#define PR_AF_INET6 23  /* same as AF_INET6 */

#if defined(_M_IX86) || defined(_X86_)

#define IS_LITTLE_ENDIAN 1
#undef  IS_BIG_ENDIAN

#define PR_BYTES_PER_BYTE   1
#define PR_BYTES_PER_SHORT  2
#define PR_BYTES_PER_INT    4
#define PR_BYTES_PER_INT64  8
#define PR_BYTES_PER_LONG   4
#define PR_BYTES_PER_FLOAT  4
#define PR_BYTES_PER_WORD	4
#define PR_BYTES_PER_DWORD	8
#define PR_BYTES_PER_DOUBLE 8

#define PR_BITS_PER_BYTE    8
#define PR_BITS_PER_SHORT   16
#define PR_BITS_PER_INT     32
#define PR_BITS_PER_INT64   64
#define PR_BITS_PER_LONG    32
#define PR_BITS_PER_FLOAT   32
#define PR_BITS_PER_WORD	32
#define PR_BITS_PER_DWORD	64
#define PR_BITS_PER_DOUBLE  64

#define PR_BITS_PER_BYTE_LOG2   3
#define PR_BITS_PER_SHORT_LOG2  4
#define PR_BITS_PER_INT_LOG2    5
#define PR_BITS_PER_INT64_LOG2  6
#define PR_BITS_PER_LONG_LOG2   5
#define PR_BITS_PER_FLOAT_LOG2  5
#define PR_BITS_PER_WORD_LOG2	5
#define PR_BITS_PER_DWORD_LOG2	6
#define PR_BITS_PER_DOUBLE_LOG2 6

#define PR_ALIGN_OF_SHORT   2
#define PR_ALIGN_OF_INT     4
#define PR_ALIGN_OF_LONG    4
#define PR_ALIGN_OF_INT64   8
#define PR_ALIGN_OF_FLOAT   4
#define PR_ALIGN_OF_WORD	4
#define PR_ALIGN_OF_DWORD	8
#define PR_ALIGN_OF_DOUBLE  4
#define PR_ALIGN_OF_POINTER 4

#define PR_BYTES_PER_WORD_LOG2	2
#define PR_BYTES_PER_DWORD_LOG2	2

#elif defined(_ALPHA_)

#define IS_LITTLE_ENDIAN 1
#undef  IS_BIG_ENDIAN

#define PR_BYTES_PER_BYTE   1
#define PR_BYTES_PER_SHORT  2
#define PR_BYTES_PER_INT    4
#define PR_BYTES_PER_INT64  8
#define PR_BYTES_PER_LONG   4
#define PR_BYTES_PER_FLOAT  4
#define PR_BYTES_PER_DOUBLE 8
#define PR_BYTES_PER_WORD   4
#define PR_BYTES_PER_DWORD  8

#define PR_BITS_PER_BYTE    8
#define PR_BITS_PER_SHORT   16
#define PR_BITS_PER_INT     32
#define PR_BITS_PER_INT64   64
#define PR_BITS_PER_LONG    32
#define PR_BITS_PER_FLOAT   32
#define PR_BITS_PER_DOUBLE  64
#define PR_BITS_PER_WORD    32

#define PR_BITS_PER_BYTE_LOG2   3
#define PR_BITS_PER_SHORT_LOG2  4
#define PR_BITS_PER_INT_LOG2    5
#define PR_BITS_PER_INT64_LOG2  6
#define PR_BITS_PER_LONG_LOG2   5
#define PR_BITS_PER_FLOAT_LOG2  5
#define PR_BITS_PER_DOUBLE_LOG2 6
#define PR_BITS_PER_WORD_LOG2   5

#define PR_BYTES_PER_WORD_LOG2  2
#define PR_BYTES_PER_DWORD_LOG2 3

#define PR_ALIGN_OF_SHORT   2
#define PR_ALIGN_OF_INT     4
#define PR_ALIGN_OF_LONG    4
#define PR_ALIGN_OF_INT64   8
#define PR_ALIGN_OF_FLOAT   4
#define PR_ALIGN_OF_DOUBLE  8
#define PR_ALIGN_OF_POINTER 4

#else /* defined(_M_IX86) || defined(_X86_) */

#error unknown processor architecture

#endif /* defined(_M_IX86) || defined(_X86_) */

#define HAVE_LONG_LONG

#ifndef NO_NSPR_10_SUPPORT

#define BYTES_PER_BYTE      PR_BYTES_PER_BYTE
#define BYTES_PER_SHORT     PR_BYTES_PER_SHORT
#define BYTES_PER_INT       PR_BYTES_PER_INT
#define BYTES_PER_INT64     PR_BYTES_PER_INT64
#define BYTES_PER_LONG      PR_BYTES_PER_LONG
#define BYTES_PER_FLOAT     PR_BYTES_PER_FLOAT
#define BYTES_PER_DOUBLE    PR_BYTES_PER_DOUBLE
#define BYTES_PER_WORD      PR_BYTES_PER_WORD
#define BYTES_PER_DWORD     PR_BYTES_PER_DWORD

#define BITS_PER_BYTE       PR_BITS_PER_BYTE
#define BITS_PER_SHORT      PR_BITS_PER_SHORT
#define BITS_PER_INT        PR_BITS_PER_INT
#define BITS_PER_INT64      PR_BITS_PER_INT64
#define BITS_PER_LONG       PR_BITS_PER_LONG
#define BITS_PER_FLOAT      PR_BITS_PER_FLOAT
#define BITS_PER_DOUBLE     PR_BITS_PER_DOUBLE
#define BITS_PER_WORD       PR_BITS_PER_WORD

#define BITS_PER_BYTE_LOG2  PR_BITS_PER_BYTE_LOG2
#define BITS_PER_SHORT_LOG2 PR_BITS_PER_SHORT_LOG2
#define BITS_PER_INT_LOG2   PR_BITS_PER_INT_LOG2
#define BITS_PER_INT64_LOG2 PR_BITS_PER_INT64_LOG2
#define BITS_PER_LONG_LOG2  PR_BITS_PER_LONG_LOG2
#define BITS_PER_FLOAT_LOG2 PR_BITS_PER_FLOAT_LOG2
#define BITS_PER_DOUBLE_LOG2    PR_BITS_PER_DOUBLE_LOG2
#define BITS_PER_WORD_LOG2  PR_BITS_PER_WORD_LOG2

#define ALIGN_OF_SHORT      PR_ALIGN_OF_SHORT
#define ALIGN_OF_INT        PR_ALIGN_OF_INT
#define ALIGN_OF_LONG       PR_ALIGN_OF_LONG
#define ALIGN_OF_INT64      PR_ALIGN_OF_INT64
#define ALIGN_OF_FLOAT      PR_ALIGN_OF_FLOAT
#define ALIGN_OF_DOUBLE     PR_ALIGN_OF_DOUBLE
#define ALIGN_OF_POINTER    PR_ALIGN_OF_POINTER
#define ALIGN_OF_WORD       PR_ALIGN_OF_WORD

#define BYTES_PER_WORD_LOG2		PR_BYTES_PER_WORD_LOG2
#define BYTES_PER_DWORD_LOG2    PR_BYTES_PER_DWORD_LOG2
#define WORDS_PER_DWORD_LOG2    PR_WORDS_PER_DWORD_LOG2

#endif /* NO_NSPR_10_SUPPORT */

#endif /* nspr_cpucfg___ */