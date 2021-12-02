test_map: map<string -> int> = {}

test_map.put|"hello" 0|
test_map.put|"world" 10|

#expected 0 10
print|test_map["hello"] test_map["world"]|

test_map.set|"hello" 100|
test_map.set|"world" 200|

# expected 100 200
print|test_map["hello"] test_map["world"]|