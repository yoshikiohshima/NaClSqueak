/* Automatically generated from Squeak on 30 April 2011 12:37:12 am 
   by VMMaker 4.4.7
 */

#define VMMAKER_VERSION "4.4.7"

/*
 * define SQ_VI_BYTES_PER_WORD 8 for a 64-bit word size VM
 * and default to SQ_VI_BYTES_PER_WORD 4 for a 32-bit word size VM
 */
#ifndef SQ_VI_BYTES_PER_WORD
# define SQ_VI_BYTES_PER_WORD 4
#endif

#define BYTES_PER_WORD SQ_VI_BYTES_PER_WORD
#define BASE_HEADER_SIZE SQ_VI_BYTES_PER_WORD
#if (BYTES_PER_WORD == 4) // 32-bit object memory
# define WORD_MASK 0xffffffff
# define SHIFT_FOR_WORD 2
# define SMALL_CONTEXT_SIZE 92
# define LARGE_CONTEXT_SIZE 252
# define SIZE_MASK 0xfc
# define LONG_SIZE_MASK 0xfffffffc
# define SIZE_4_BIT 0
# define MARK_BIT 0x80000000
# define ROOT_BIT 0x40000000
# define ALL_BUT_MARK_BIT 0x7fffffff
# define ALL_BUT_ROOT_BIT 0xbfffffff
# define ALL_BUT_TYPE_MASK 0xfffffffc
# define ALL_BUT_MARK_BIT_AND_TYPE_MASK 0x7ffffffc
# define ALL_BUT_HASH_BITS 0xe001ffff
#else // 64-bit object memory
# define WORD_MASK 0xffffffffffffffff
# define SHIFT_FOR_WORD 3
# define SMALL_CONTEXT_SIZE 184
# define LARGE_CONTEXT_SIZE 504
# define SIZE_MASK 0xf8
# define LONG_SIZE_MASK 0xfffffffffffffff8
# define SIZE_4_BIT 4
# define MARK_BIT 0x8000000000000000
# define ROOT_BIT 0x4000000000000000
# define ALL_BUT_MARK_BIT 0x7fffffffffffffff
# define ALL_BUT_ROOT_BIT 0xbfffffffffffffff
# define ALL_BUT_TYPE_MASK 0xfffffffffffffffc
# define ALL_BUT_MARK_BIT_AND_TYPE_MASK 0x7ffffffffffffffc
# define ALL_BUT_HASH_BITS 0xffffffffe001ffff
#endif //  (BYTES_PER_WORD == 4)

