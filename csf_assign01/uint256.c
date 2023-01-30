#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "uint256.h"

// Create a UInt256 value from a single uint64_t value.
// Only the least-significant 64 bits are initialized directly,
// all other bits are set to 0.
UInt256 uint256_create_from_u64(uint64_t val) {
  UInt256 result;
  result.data[0] = val;
  result.data[1] = 0U;
  result.data[2] = 0U;
  result.data[3] = 0U;

  // TODO: implement
  return result;
}

// Create a UInt256 value from an array of 4 uint64_t values.
// The element at index 0 is the least significant, and the element
// at index 3 is the most significant.
UInt256 uint256_create(const uint64_t data[4]) {
  UInt256 result;
  for(int i = 0 ; i < 4 ; i++) {
    result.data[i] = data[i];
  }
  // TODO: implement
  return result;
}

// Create a UInt256 value from a string of hexadecimal digits.
UInt256 uint256_create_from_hex(const char *hex) {
  UInt256 result;
  size_t len = strlen(hex);
  char *new = hex;
  char *ptr;
  if(len>64) {
    strncpy(new,new+len-64,64);
    len = strlen(new);
    printf("%d",len);
  }
  int totallen = len;
  result.data[0] = 0U;
  result.data[1] = 0U;
  result.data[2] = 0U;
  result.data[3] = 0U;
  int count = 16;
  int i = 0;
  while(len>16 && i < 4){
    char temp[16];
    strncpy(temp,new+len-totallen,count);
    result.data[i] = strtoul(temp,&ptr,16);
    len = len - 16;
    i++;
  }
  if(len > 0) {
    char temp[len];
    strncpy(temp,new+len-totallen,count);
    result.data[i] = strtoul(temp,&ptr,16);
  }

  // TODO: implement
  return result;
}

// Return a dynamically-allocated string of hex digits representing the
// given UInt256 value.
char *uint256_format_as_hex(UInt256 val) {
  char *hex = NULL;
  char *buf;
  buf = (char *) malloc(20);
  //uint64_t val = /* some value */;

  //sprintf(buf, "%lx", val);    // format without leading 0s
  for(int i = 0 ; i < 4 ; i++) {
    sprintf(buf, "%016lx", val.data[i]); // format with leading 0s
    strcat(hex,buf);
  }
  // TODO: implement
  free(buf);
  return hex;
}

// Get 64 bits of data from a UInt256 value.
// Index 0 is the least significant 64 bits, index 3 is the most
// significant 64 bits.
uint64_t uint256_get_bits(UInt256 val, unsigned index) {
  uint64_t bits;
  bits = val.data[index];
  // TODO: implement
  return bits;
}

// Compute the sum of two UInt256 values.
UInt256 uint256_add(UInt256 left, UInt256 right) {
  UInt256 sum;
  int carry = 0;
  for(int i = 0 ; i < 4 ; i++) {
    sum.data[i] = left.data[i] + right.data[i] + carry;
    if (sum.data[i] < left.data[i] ) {
      //|| sum.data[i] < right.data[i]
      carry = 1;
      //sum.data[i] = 0;
    } else {
      carry = 0;
    }
  }
  return sum;
}

// Compute the difference of two UInt256 values.
UInt256 uint256_sub(UInt256 left, UInt256 right) {
  UInt256 result;
  for(int i = 0 ; i < 4 ; i++){
    right.data[i] = ~(right.data[i])+1;
  }
  result = uint256_add(left,right);
  
  return result;
}

// Compute the product of two UInt256 values.
UInt256 uint256_mul(UInt256 left, UInt256 right) {
  UInt256 product;
  // TODO: implement
  return product;
}
