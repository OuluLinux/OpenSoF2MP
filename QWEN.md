# Fix Notes for OpenSoF2MP

This document records important fixes made to the OpenSoF2MP codebase for future reference.

## 64-bit Compilation Fixes

### 1. Pointer-to-integer cast issues

**Problem**: Cast from pointer types to `int` loses precision on 64-bit systems.

**Affected Files**:
- `/code/client/snd_mem.cpp`
- `/code/Ratl/ratl_common.h`

**Specific Fixes**:
1. In `snd_mem.cpp` line 122:
   - Changed `Com_Printf ("0x%x : %s (%d)\n", (int)(data_p - 4), str, iff_chunk_len);`
   - To `Com_Printf ("0x%p : %s (%d)\n", (void*)(data_p - 4), str, iff_chunk_len);`

2. In `snd_mem.cpp` line 196:
   - Fixed `info.dataofs = data_p - wav;` to be cast appropriately

3. In `ratl_common.h` multiple locations:
   - Changed `int(&((TStorage *)0)->nodeData)-int(&((TStorage *)0)->value)` 
   - To `(ptrdiff_t)(&((TStorage *)0)->nodeData)-(ptrdiff_t)(&((TStorage *)0)->value)`
   - Also updated similar pointer arithmetic patterns to use `ptrdiff_t` where appropriate

### 2. C++ Standard Library Includes

**Problem**: Missing includes for `std::string` type.

**Affected Files**:
- `/code/client/snd_mem.cpp`
- `/code/client/snd_music.cpp` 
- `/code/client/snd_ambient.cpp`

**Fix**: Added the following include to each file:
```cpp
#ifdef __cplusplus
#include <string>
using std::string;
#endif
```

### 3. Notes
- Use `ptrdiff_t` for pointer arithmetic results that need to be stored as integers
- Use `%p` format specifier for printing pointer values
- Always include appropriate standard library headers when using STL types