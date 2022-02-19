import sys

class Logger(object):
    def fatal_error(text, exit=False):
        print("Oppsie woopsie~! %s" %text)
        if exit:
            sys.exit(-1)