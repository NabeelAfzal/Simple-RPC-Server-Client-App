// This source file basically contains the function to compare both input 
// strings to check for a match.

#include <string.h>
#include "compare.h"

/************************************************************************
*  
* @purpose function to compare two strings to check for a match
*
* @param const char*    str       String containing data read from config file
* @param const char*    prefix    String containing the text with which the data
*                                 is being matched
*    
* @returns int    0 (SUCCESS) or 1 (FAILURE)
* @notes none
* @end
*
***********************************************************************/
int starts_with(const char *str, const char *prefix) {
  if (memcmp(str, prefix, strlen(prefix)) == 0)
    return 1;
  else
    return 0;
}
