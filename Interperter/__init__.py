from Common.Token import *
from Utility import Logger

# TODO: Make an actual interperter, this is a draft

class Interperter:
    tokenList = []
    index = 0

    def __init__(self, tokenList):
        self.tokenList = tokenList
        self.index = -1

    def advance(self):
        if not self.haveNext():
            return None
        self.index += 1
        return self.tokenList[self.index]

    def haveNext(self):
        return len(self.tokenList) > self.index+1

    def run(self):
        variables = {}
        while self.haveNext():
            token = self.advance()
            if token.tokenType == Keyword.AWOO:
                content = self.advance()
                if content == None or not (content.tokenType in [Constant.BOOL, Constant.INT, Constant.VARIABLE, Constant.STRING]):
                    Logger.fatal_error("A swyntax ewwor haw bween dwetected!\n   '%s' at lwine %s and cwolumn %s\n   Expected an 'int', 'bool', 'string' or Variable after 'awoo' keyword" % (token.originalWord, token.line, token.offset), True)
                else:
                    out = ""
                    if content.tokenType == Constant.VARIABLE:
                        if content.value in variables:
                            out = variables[content.value]
                        else:
                            Logger.fatal_error("A swyntax ewwor haw bween dwetected!\n   '%s' at lwine %s and cwolumn %s\n   Variable '%s' is not defined" % (token.originalWord, token.line, token.offset, content.value), True)
                    else:
                        out = content.value
                    print(out)
            elif token.tokenType == Keyword.SET:
                variable = self.advance()
                if variable == None or not variable.tokenType == Constant.VARIABLE:
                    Logger.fatal_error("A swyntax ewwor haw bween dwetected!\n   '%s' at lwine %s and cwolumn %s\n   Expected a variable name after 'set' keyword" % (token.originalWord, token.line, token.offset), True)
                data = self.advance()
                if data == None or not (data.tokenType in [Constant.BOOL, Constant.INT, Constant.STRING]):
                    Logger.fatal_error("A swyntax ewwor haw bween dwetected!\n   '%s' at lwine %s and cwolumn %s\n   Expected an 'int', 'bool' or 'string' after the variable name" % (token.originalWord, token.line, token.offset), True)
                variables[variable.value] = data.value