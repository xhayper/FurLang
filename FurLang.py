#!/usr/bin/env python3

from Interperter import Interperter
from Lexer import Lexer
import sys

if __name__ == "__main__":
    content = open(sys.argv[1], "r").read()
    Interperter(Lexer(content).make_tokens()).run()