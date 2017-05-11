import sys
from subprocess import Popen, PIPE

# sys.argv[1] is the program name
# each test returns a score between 0 and 100

PIXEL_LEVEL_TOLERANCE = .001

def passed(percentage=100):
    return percentage

def failed():
    return 0

## helper functions
def get_output(prog, radius, sigma):
    # shell> limit prog radius sigma
    p = Popen(["limit", prog, str(radius), str(sigma)], 
        stdout=PIPE, stderr=PIPE)
    o, e = p.communicate()
    return o

def get_parsed_output(prog, radius, sigma):
    o = get_output(prog, radius, sigma)
    if len(o) == 0:
        return []
    # split on any whitespace
    items = o.split(None)
    if len(items) != (2*radius + 1) * (2*radius + 1):
        return []
    try:
        items = map(float, items)
        return items
    except ValueError:
        return []

def get_expected_output(filename):
    with open(filename, 'r') as f:
        return f.read()

def get_parsed_expected_output(filename):
    return map(float, get_expected_output(filename).split(None))

def equal_within_tolerance(i, j):
    return abs(i-j) <= PIXEL_LEVEL_TOLERANCE

def compare_with_expected(a, b):
    wrong = 0 
    for i in xrange(len(a)):
        if not equal_within_tolerance(a[i], b[i]):
            wrong += 1
    return int(100 - (wrong * 100.0 / len(a)))

def test_with_expected(a, b):
    for i in xrange(len(a)):
        if not equal_within_tolerance(a[i], b[i]):
            failed()
    passed()

def test_radius_num_lines(output, radius):
    if len(output.splitlines()) == (2*radius) + 1:
        return passed()
    else:
        return failed()

def test_radius_line_items(output, radius):
    lines = output.splitlines()
    for line in lines:
        if len(line.split()) != (2*radius) + 1:
            return failed()
    return passed()

def test_radius_num_items(output, radius):
    num_items = len(output.split(None))
    total = (2*radius + 1) * (2*radius + 1)
    if num_items >= 2 * total:
        return failed()
    else:
        return passed(100 - (abs(total - num_items) * 100.0 / total))

## testing some base formatting and output for input1
def test_1_base_1(prog):
    radius = 1
    o = get_output(prog, radius, 1)
    return test_radius_num_lines(o, radius)

def test_1_base_2(prog):
    radius = 1
    o = get_output(prog, radius, 1)
    return test_radius_line_items(o, radius)

def test_1_base_3(prog):
    radius = 1
    o = get_output(prog, radius, 1)
    return test_radius_num_items(o, radius)

def test_1_base_4(prog):
    radius = 1
    actual = get_parsed_output(prog, radius, 1)
    expected = get_parsed_expected_output("test_output/output1.txt")
    if(len(actual) != len(expected)):
        return failed()
    else:
        return compare_with_expected(actual, expected)

def test_2_base_1(prog):
    radius = 2
    o = get_output(prog, radius, 3)
    return test_radius_num_lines(o, radius)

def test_2_base_2(prog):
    radius = 2
    o = get_output(prog, radius, 3)
    return test_radius_line_items(o, radius)

def test_2_base_3(prog):
    radius = 2
    o = get_output(prog, radius, 3)
    return test_radius_num_items(o, radius)

def test_2_base_4(prog):
    radius = 2
    actual = get_parsed_output(prog, radius, 3)
    expected = get_parsed_expected_output("test_output/output2.txt")
    if(len(actual) != len(expected)):
        return failed()
    else:
        return compare_with_expected(actual, expected)

def test_3_base_1(prog):
    radius = 5
    o = get_output(prog, radius, 4)
    return test_radius_num_lines(o, radius)

def test_3_base_2(prog):
    radius = 5
    o = get_output(prog, radius, 4)
    return test_radius_line_items(o, radius)

def test_3_base_3(prog):
    radius = 5
    o = get_output(prog, radius, 4)
    return test_radius_num_items(o, radius)

def test_3_base_4(prog):
    radius = 5
    actual = get_parsed_output(prog, radius, 4)
    expected = get_parsed_expected_output("test_output/output3.txt")
    if(len(actual) != len(expected)):
        return failed()
    else:
        return compare_with_expected(actual, expected)


def main():
    tests = [test_1_base_1, 
             test_1_base_2, 
             test_1_base_3, 
             test_1_base_4,
             test_2_base_1, 
             test_2_base_2, 
             test_2_base_3, 
             test_2_base_4, 
             test_3_base_1, 
             test_3_base_2, 
             test_3_base_3, 
             test_3_base_4]

    scores = [] 
    if len(sys.argv) >= 1:
        for t in tests:
            scores.append(t(sys.argv[1]))
        print "({})".format(" ".join(map(str, scores)))
    else:
        print ""

if __name__ == '__main__':
    main()
