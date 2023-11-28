#ifndef TYPES_H
#define TYPES_H

#include "tokens.h"

typedef struct Integer {
    TokenType type;
    int value;
} Integer;

typedef struct String {
    TokenType type;
    char *string;
} String;

typedef struct DataType {
    String string;
    Integer integer;
} DataType;

typedef struct Object {
    TokenType token_type;
    DataType data_type;
} Object;

#endif
