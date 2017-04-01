// This file defines some bit utilities.

#ifndef BASE_BITS_H_
#define BASE_BITS_H_

#include <stddef.h>
#include <stdint.h>

namespace base {
namespace bits {

// Returns the integer i such as 2^i <= n < 2^(i+1)
inline int Log2Floor(uint32_t n) {
  if (n == 0)
    return -1;
  int log = 0;
  uint32_t value = n;
  for (int i = 4; i >= 0; --i) {
    int shift = (1 << i);
    uint32_t x = value >> shift;
    if (x != 0) {
      value = x;
      log += shift;
    }
  }
  return log;
}

// Returns the integer i such as 2^(i-1) < n <= 2^i
inline int Log2Ceiling(uint32_t n) {
  if (n == 0) {
    return -1;
  } else {
    // Log2Floor returns -1 for 0, so the following works correctly for n=1.
    return 1 + Log2Floor(n - 1);
  }
}

// Round up |size| to a multiple of alignment, which must be a power of two.
inline size_t Align(size_t size, size_t alignment) {
  return (size + alignment - 1) & ~(alignment - 1);
}

}  // namespace bits
}  // namespace base

#endif  // BASE_BITS_H_
