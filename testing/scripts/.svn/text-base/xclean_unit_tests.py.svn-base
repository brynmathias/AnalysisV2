#!/usr/bin/env python
import setupSUSY
import unittest
#import xclean.clonevector_tests
#import xclean.basic_tests

if __name__ == '__main__':
    testcases=["xclean.clonevector_tests.TestCloneVector",
               "xclean.basic_tests.TestBasic"]
    suite = unittest.TestLoader().loadTestsFromNames(testcases)
    print "="*50
    print "Cross Cleaner Unit Tests"
    print "="*50
    unittest.TextTestRunner(verbosity=2).run(suite)
