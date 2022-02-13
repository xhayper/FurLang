iota_counter = 0
def iota():
    global iota_counter
    iota_counter += 1
    return iota_counter

class Keyword(object):
    IF = iota()
    ELSE = iota()
    ELSEIF = iota()
    AWOO = iota() # Basiclly, Print
    BARK = iota() # Basiclly, Return
    SET = iota()

class Operator(object):
    ADD = iota()
    SUB = iota()
    DIV = iota()
    MOD = iota()

class Constant(object):
    INT = iota()
    BOOL = iota()
    VARIABLE = iota()

class Token:
    tokenType = ""
    value = ""
    # Analysis
    line = 0
    offset = 0
    originalWord = ""

    def __init__(self, tokenType, value, line, offset, originalWord):
        self.tokenType = tokenType
        self.value = value
        self.line = line
        self.offset = offset
        self.originalWord = originalWord
    
    def __repr__(self):
        return "< TOKEN: %s, VALUE: %s, LINE: %s, OFFSET: %s, ORIGINAL_WORD: %s >" % (self.tokenType, self.value, self.line, self.offset, self.originalWord)