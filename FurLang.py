#!/usr/bin/env python3

from Lexer import Lexer
import sys

if __name__ == "__main__":
    content = open(sys.argv[1], "r").read()
    Lex = Lexer(content)
    # Lex.make_tokens()
    print(Lex.make_tokens())