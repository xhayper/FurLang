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
        while self.haveNext():
            token = self.advance()
            if token.tokenType == Keyword.AWOO:
                content = self.advance()
                if content == None or not (content.tokenType in [Constant.BOOL, Constant.INT]):
                    Logger.fatal_error("A swyntax ewwor haw bween dwetected!\n   \"%s\" at lwine %s and cwolumn %s\n   Expected an \"int\" or \"bool\" after \"awoo\" keyword" % (token.originalWord, token.line, token.offset), True)
                else:
                    print(content.value)
            