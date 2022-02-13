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

class Operator(object):
    ADD = iota()
    SUB = iota()
    DIV = iota()
    MOD = iota()

class Constant(object):
    INT = iota()
    BOOL = iota()

class Token:
    tokenType = ""
    value = ""

    def __init__(self, tokenType, value):
        self.tokenType = tokenType
        self.value = value
    
    def __repr__(self):
        return "< TOKEN: %s, VALUE: %s >" % (self.tokenType, self.value)