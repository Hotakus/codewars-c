/**
  ******************************************************************************
  * @file      : determine_prime.c
  * @author    : Hotakus
  * @brief     : None
  * @attention : None
  * @date      : 2023/6/16
  ******************************************************************************
  */

#include "determine_prime.h"
#include "../algorithms/ba.h"

bool prime_determine(int num, bool opt) {
    if (num <= 1)
        return false;
    for (int i = 2; i <= (opt ? (int)h_fast_sqrt((float)num) : (num >> 1)); ++i)
        if (num % i == 0)
            return false;
    return true;
}


bool prime_eratosthenes(int num) {
    return 0;
}


bool prime_euler(int num) {
    return 0;
}
