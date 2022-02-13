from Common.Token import *
from Utility import Logger
import re

BOOL = ["true", "false"]
RESET_WORD = [" ", "\n", "\0"]
SKIP = [*RESET_WORD, "\t"]
COMMENT = ["~owo~", "~uwu~", "~blep~"]

class Lexer:
    def __init__(self, source):
        self.source = source
    
    def parseInstruction(self, word):
        tokenType = None
        tokenValue = None
        if word == "awoo":
            tokenType = Keyword.AWOO
        elif word == "set":
            tokenType = Keyword.SET
        else:
            tokenType = Constant.VARIABLE
            tokenValue = word
        return (tokenType, tokenValue)
    
    def make_tokens(self):
        tokenList = []
        # Needed
        word = ""
        index = 0
        # Analysis
        line = 0
        offset = 0
        # Comment
        in_single_line_comment = False
        in_multi_line_comment = False
        while 1:
            if index >= len(self.source): # End of file
                break

            while not self.source[index] in RESET_WORD:
                word += self.source[index]
                index += 1
                offset += 1
                if index >= len(self.source): # End of file
                    break

            if word == "~owo~":
                in_multi_line_comment = True
            
            if word == "~blep~":
                in_single_line_comment = not in_multi_line_comment

            if word == "~uwu~":
                if not in_multi_line_comment:
                    Logger.fatal_error("A swyntax ewwor haw bween dwetected!\n   \"%s\" at lwine %s and cwolumn %s\n   Expected open comment block" % (word, line+1, offset-len(word)), True)
                else:
                    in_multi_line_comment = False

            if not word in COMMENT and word != "" and not in_single_line_comment and not in_multi_line_comment:   
                if not re.findall("\D", word):
                    tokenList.append(Token(Constant.INT, int(word), line+1, offset-len(word), word))
                elif word in BOOL:
                    tokenList.append(Token(Constant.BOOL, word == "true", line+1, offset-len(word), word))
                else:
                    tokenType, tokenValue = self.parseInstruction(word)
                    if tokenType:
                        tokenList.append(Token(tokenType, tokenValue, line+1, offset-len(word), word))
                    else:
                        Logger.fatal_error("A swyntax ewwor haw bween dwetected!\n   \"%s\" at lwine %s and cwolumn %s\n   Expected an keyword!" % (word, line+1, offset-len(word)), True)

            if len(self.source) > index and self.source[index] == "\n":
                line += 1
                offset = 0
                in_single_line_comment = False

            word = ""
            index += 1
            offset += 1
        return tokenList


    def try_get_int(word):
        return 0