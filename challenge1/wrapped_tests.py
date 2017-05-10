'''
    This script generates different test score for insertion sort
'''
import sys
import math
from subprocess import Popen, PIPE

# sys.argv[1] is the program name
# each test returns a score between 0 and 100

PERCENTAGE_ERROR_ALLOWED = 2
ERROR_CODE = -42

## helper functions
def get_output(input_val):
    ''' call the shell '''
    # cmd = ["limit", sys.argv[1]] + input_val
    cmd = [sys.argv[1]] + input_val
    proc = Popen(cmd,
                 stdout=PIPE,
                 stderr=PIPE)
    stdout, _ = proc.communicate()
    return stdout

def get_parsed_output(input_list):
    stdout = get_output(input_list)
    try:
        res = float(stdout)
        return res
    except ValueError:
        return ERROR_CODE

def gauss_2d_oracle(lst):
    x = lst[0]
    y = lst[1]
    s = lst[2]
    return (1.0/(2.0*math.pi*s*s))*math.exp(-(x*x+y*y)/(2.0*s*s))

def get_relative_score(res, exp):
    if res == ERROR_CODE:
        return 0
    rel_error = math.fabs((res - exp) / float(exp)) * 100
    if rel_error < PERCENTAGE_ERROR_ALLOWED:
        return 100
    if rel_error > 100:
        return 0
    else:
        return 100 - rel_error

def test_1():
    input_list = [0, 0, 1]
    res = get_parsed_output([str(item) for item in input_list])
    expected_output = gauss_2d_oracle(input_list)
    return get_relative_score(res, expected_output)

def test_2():
    input_list = [1, 2, 1]
    res = get_parsed_output([str(item) for item in input_list])
    expected_output = gauss_2d_oracle(input_list)
    return get_relative_score(res, expected_output)

def test_3():
    input_list = [10, 20, 15]
    res = get_parsed_output([str(item) for item in input_list])
    expected_output = gauss_2d_oracle(input_list)
    return get_relative_score(res, expected_output)

def test_4():
    input_list = [4, 4, 4]
    res = get_parsed_output([str(item) for item in input_list])
    expected_output = gauss_2d_oracle(input_list)
    return get_relative_score(res, expected_output)

def main():
    ''' main test driver '''
    tests = [
        test_1,
        test_2,
        test_3,
        test_4
    ]

    scores = []
    if len(sys.argv) >= 1:
        for test in tests:
            scores.append(test())
        print "({})".format(" ".join(map(str, scores)))
    else:
        print ""

if __name__ == '__main__':
    main()
