#ifndef _UTILS
#define _UTILS
#include <stdlib.h>

/*
 * \brief Test equality between arrays of int of same length
 * \param a an array of int to compare
 * \param b an array of int to compare
 * \param la the length of \a a greater or equal to 0
 * \param lb the length of \a b greater or equal to 0
 * \internal test if \a a and \a b have the same length then
 *           test equality of all elements of the two arrays \a a and \a b
 * \return 1 if \a a and \a b have the same content or are empty else 0
 */
int arraysEqual(int* a, int* b, int la, int lb) {
  if (la != lb)
    return 0;
  
  if (la == 0)
    return 1;

  for (int i=0; i<la; i++) {
    if (a[i] != b[i]) 
       return 0;
  }
  return 1;
}

/*
 * \brief Return a copy of an array of int knowing it's length
 * \param a the array to copy
 * \param l the length of the array \a a
 * \internal allocate memory space for the copy then copy elements of \a a one
 *           by one
 * \return a deep copy of the array \a a
 */
int* deepCopy(int* a, int l) {
  int* aCopy = (int*) malloc(l*sizeof(int));
  for (int i=0; i<l; i++)
    aCopy[i] = a[i];
  
  return aCopy;
}

#endif
