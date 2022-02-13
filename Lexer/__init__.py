from Common.Token import *
import re

BOOL = ["true", "false"]
RESET_WORD = [" ", "\n", "\0"]
SKIP = [*RESET_WORD, "\t"]

class Lexer:
    def __init__(self, source):
        self.source = source
    
    def parseInstruction(self, word):
        tokenType = None
        tokenValue = None
        if word == "awoo":
            tokenType = Keyword.AWOO
        return (tokenType, tokenValue)
    
    def make_tokens(self):
        tokenList = []
        word = ""
        line = 0
        i = 0
        in_single_line_comment = False
        in_multi_line_comment = False
        while 1:
            if i >= len(self.source): # End of file
                break

            while not self.source[i] in RESET_WORD:
                word += self.source[i]
                i += 1
                if i >= len(self.source): # End of file
                    break

            if word == "~owo~":
                in_multi_line_comment = True
            
            if word == "~blep~":
                in_single_line_comment = not in_multi_line_comment

            if not in_single_line_comment and not in_multi_line_comment:   
                if not re.findall("\D", word):
                    tokenList.append(Token(Constant.INT, int(word)))
                elif word in BOOL:
                    tokenList.append(Token(Constant.BOOL, word == "true"))
                else:
                    tokenType, tokenValue = self.parseInstruction(word)
                    if tokenType:
                        tokenList.append(Token(tokenType, tokenValue))
                    else:
                        raise SyntaxError(word)
            
            if word == "~uwu~":
                if in_multi_line_comment:
                    in_multi_line_comment = False
                else:
                    raise SyntaxError(word)

            if len(self.source) > i and self.source[i] == "\n":
                line += 1
                in_single_line_comment = False

            word = ""
            i += 1
        
        return tokenList


    def try_get_int(word):
        return 0