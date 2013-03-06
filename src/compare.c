// This source file basically contains the function to compare both input 
// strings to check for a match.

#include <string.h>
#include "compare.h"

// Compare both strings to check for match.
int starts_with(const char *str, const char *prefix) {
  if (memcmp(str, prefix, strlen(prefix)) == 0)
    return 1;
  else
    return 0;
}
