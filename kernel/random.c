//
// Created by Jack Nunley on 2/21/22.
//

#include "random.h"
#include "types.h"

int seed = 0;

uint random() {
  const uint modulus = 65537;
  const uint a = 75;
  const uint c = 76;
  seed = (a * seed + c) % modulus;
  return seed;
}

