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
  int len = strlen(hex);
  char *new = hex;
  //char *ptr;
  if(len>64) {
    memcpy(new,new+len-64,64);
    
    len = strlen(new);
    //puts(len);
  }
  //int totallen = len;
  uint64_t t = 0UL;
  result = uint256_create_from_u64(t);
  //UInt256 temp;
  //int count = 16;
  int i = 0;
  while(len > 0 && i < 4) {
    int size = 16;
    if (len < 16) {
      size = len;
    }
    char buf[size+1];
    memset(buf,buf,size+1);
    if(len < 16 || i == 3) {
      
       memcpy(buf,new,size);
    } else {
      memcpy(buf,new+len-size,size);
    }
    len -= size;
    result.data[i] = strtoul(buf,NULL,16);
    //free(buf);
    i++;
  }
  // TODO: implement
  return result;
}

char* uint64_tashex(uint64_t val) {
  char *buf = (char *) malloc((16+1)*sizeof(char));
  int add = 0;
  add += sprintf(buf, "%lx", val);  
  return buf;
}

// Return a dynamically-allocated string of hex digits representing the
// given UInt256 value.
char *uint256_format_as_hex(UInt256 val) {
  //char *hex = NULL;
  
  int alloc;
  for(int i = 3 ; i >= 0 ; i--) {
    if (val.data[i] != 0) {
      alloc = i;
      break;
    }
    if(val.data[i]==0UL && i== 0) {
      char *buf = (char *) malloc((alloc*16+1)*sizeof(char));
      int zero = 0;
      sprintf(buf, "%lx", zero);
      return buf;
    }
  }
  
  int add =0;
  char *buf = (char *) malloc((alloc*16+1)*sizeof(char));
  //uint64_t val = /* some value */;

  //sprintf(buf, "%lx", val);    // format without leading 0s
  
  for(int i = alloc ; i >= 0 ; i--){
    
    
    if(i!=alloc){
      
      add += sprintf(buf+add, "%016lx", val.data[i]);
      //printf("%d",add);
    } else {
      add += sprintf(buf+add, "%lx", val.data[i]);  
      //printf("%d",add);
    }
  }
  // while(val.data[i] != 0 && i < alloc) {
  //   if (i == 3 || val.data[i+1] == 0) {
  //     sprintf(buf, "%lx", val.data[i]);     
  //   } else {
      
      
  //   }
    
  //   i++;
  // }
  // TODO: implement
  //free(buf);
  return buf;
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
    if (sum.data[i] < left.data[i] || sum.data[i] < right.data[i]) {
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
    right.data[i] = ~(right.data[i]);
  }
  UInt256 one = uint256_create_from_u64(1UL);
  right = uint256_add(right,one);
  result = uint256_add(left,right);
  
  return result;
}

// Compute the product of two UInt256 values.
UInt256 uint256_mul(UInt256 left, UInt256 right) {
  UInt256 product;
  // TODO: implement
  return product;
}

int uint256_bit_is_set(UInt256 val, unsigned index){
  int i = index%64; 
  if(val.data[i] & (1<<i)) {
    return 1;
  } else {
    return 0;
  }
}
UInt256 uint256_leftshift(UInt256 val, unsigned shift){
  
}