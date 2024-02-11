```
EXPR -> LITERAL | UNARY | BINARY | GROUPING

LITERAL -> number | string | "TRUE" | "FALSE"

UNARY -> ("!" | "-") EXPR

BINARY -> EXPR OP EXPR
OP -> "+" | "-" | "*" | "/" | "%" |
      "==" | "!=" | "<" | ">" | ">=" | "<="

GROUPING -> "(" EXPR ")"
```
