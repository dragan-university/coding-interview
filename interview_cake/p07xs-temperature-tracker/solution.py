"""
7 - temperature tracker
"""
import traceback

DEBUG_LEVEL = 0

class TempTracker:
    def __init__(self):
        self.max_temp = -float('inf')
        self.min_temp = float('inf')
        self.mean_temp = float(0)
        self.mode_temp = None
        self.temp_count = {}
        self.size = 0

    def insert(self, t):
        if DEBUG_LEVEL>5: print('insert {}'.format(t))
        self.max_temp = max(self.max_temp, t)
        self.min_temp = min(self.min_temp, t)
        
        self.mean_temp = float(self.mean_temp*self.size + t)/(self.size+1)
        if DEBUG_LEVEL>7: print('mean {}'.format(self.mean_temp))

        if t in self.temp_count:
            self.temp_count[t] += 1
        else:
            self.temp_count[t] = 1

        if not self.mode_temp or self.temp_count[t] > self.temp_count[self.mode_temp]:
            self.mode_temp = t

        self.size += 1

    def get_max(self):
        return self.max_temp

    def get_min(self):
        return self.min_temp

    def get_mean(self):
        return self.mean_temp

    def get_mode(self):
        return self.mode_temp


def test_driver(temperatures, expected_result):
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    print('temperatures: {}\nexpected: {}'.format(temperatures, expected_result))

    tt = TempTracker()
    for t in temperatures:
        tt.insert(t)

    actual_result = {
        'max_temp': tt.get_max(),
        'min_temp': tt.get_min(),
        'mean_temp': tt.get_mean(),
        'mode_temp': tt.get_mode(),
    }

    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))
    print('')

def test_12336():
    temperatures = [1,2,3,3,6]
    expected = {
        'max_temp': 6,
        'min_temp': 1,
        'mean_temp': 3.0,
        'mode_temp': 3,
    }
    test_driver(temperatures, expected)

def test_12336663():
    temperatures = [1,2,3,3,6,6,6,3]
    expected = {
        'max_temp': 6,
        'min_temp': 1,
        'mean_temp': 30.0/8.0,
        'mode_temp': 6,
    }
    test_driver(temperatures, expected)

test_12336()
test_12336663()
