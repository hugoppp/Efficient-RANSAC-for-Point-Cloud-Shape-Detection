#ifndef CUSTOM_ALLOC_H
#define CUSTOM_ALLOC_H

#if defined(__SSE__) || defined(_M_X64) || (defined(_M_IX86_FP) && _M_IX86_FP >= 1)
#define MISC_LIB_SSE_SUPPORTED
#include <xmmintrin.h>
#endif

// Define the CUSTOM_ALLOC macro
#if defined(MISC_LIB_SSE_SUPPORTED)
#define CUSTOM_ALLOC(size, alignment) ((void*)_mm_malloc((size), (alignment)))
#else
#define CUSTOM_ALLOC(size, alignment) ((void*)malloc((size)))
#endif

// Define the CUSTOM_FREE macro
#if defined(MISC_LIB_SSE_SUPPORTED)
#define CUSTOM_FREE(ptr) _mm_free(ptr)
#else
#define CUSTOM_FREE(ptr) free(ptr)
#endif

#endif // MiscLib__CUSTOM_ALLOC