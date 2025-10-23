#ifndef GAME_BYTE_WRAPPER_H
#define GAME_BYTE_WRAPPER_H

// Prevent C++17 std::byte from being defined
#ifdef __cplusplus
#if __cplusplus >= 201703L
#define _GLIBCXX_USE_STD_BYTE 0
#define _HAS_STD_BYTE 0
#undef __cpp_lib_byte
#endif
#endif

#include "q_shared.h"

#endif // GAME_BYTE_WRAPPER_H
