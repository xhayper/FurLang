from Common.Token import *

# TODO: Make an actual interperter, this is a draft

class Interperter:
    tokenList = []
    index = 0

    def __init__(self, tokenList):
        self.tokenList = tokenList
        self.index = -1

    def advance(self):
        self.index += 1
        if not self.haveNext():
            return None
        return self.tokenList[self.index]

    def haveNext(self):
        return len(self.tokenList) > self.index

    def run(self):
        while self.haveNext():
            token = self.advance()
            if token.tokenType == Keyword.AWOO:
                content = self.advance()
                if not (content.tokenType in [Constant.BOOL, Constant.INT]):
                    raise SyntaxError(token.value)
                else:
                    print(content.value)
            self.index += 1
            