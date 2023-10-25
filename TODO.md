# Moon
Every programming language works the same. 
1. Read source code.
2. Produce an output.

To produce output there needs to be context. To get context there needs to be a grammar to understand what each token does. The grammar is in grammar.md. To understand the grammar there are two parts to this.
1. Lexing. To break the input into tokens, tokens contain essentially information about what something means. Such as if something is a function or variable.
2. Parsing. To take the tokens generated from lexing and structure them by placing them into ASTs.

# Cook up a grammar
Look at grammar.md

# Write a parser
- [ ] Turn everything into a token via lexing.
- [ ] Parse the tokens into ASTs

# Write a compiler
- [Language zoo](https://plzoo.andrej.com/) - A site filled with smaller implementations of already popular languages that can be used as reference on how to build a specific feature a language has.
