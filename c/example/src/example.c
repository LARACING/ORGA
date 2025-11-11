/**
 * @file example.c
 * @brief Implements the example public API.
 * @date 2025-11-09
 * @version 1.0
 */

#include "public_api.h"
#include "example.h"

int public_function(int argument) {
    
    return argument;
}

int internal_process(int i) {
    return i;
}