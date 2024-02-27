Expr -> Literal | Unary | Binary | Grouping
Literal -> True | False | Number | String
Unary -> ("!" | "-") Expr
Op -> "+" | "-" | "*" | "/" | "%" | "==" | "!=" | "<" | ">" | ">=" | "<="
Binary -> Expr Op Expr
Grouping -> "(" Expr ")"
