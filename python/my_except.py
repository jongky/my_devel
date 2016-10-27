x = 10
def foo():
    try:
        x = spam
        x += 1
        print x
    #  except Exception as e:
    except NameError as e:
        print "[## JK-Test-11] Exception: Name Error = %r happend here !!" %(e)
    except TypeError as e:
        print "[## JK-Test-12] Exception: Type Error = %r happend here !!" %(e)
    # except UnboundLocalError as e:
    except ValueError as e:
        print "[## JK-Test-13] Exception: Value Error= %r !!! " %(e)
    except Exception as e:
        print "[## JK-Test-14] Exception happend : %r --->" %(e)

print "[## JK-Test-01] Test Begin --->"
foo()
