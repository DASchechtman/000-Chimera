test_map: map<int -> char> = {}
test_map.put|0 'a'|
test_map.put|1 'b'|
test_map.put|2 'c'|
test_map.put|3 'd'|
test_map.put|4 'e'|
test_map.put|5 'f'|
test_map.put|6 'g'|
test_map.put|7 'h'|
test_map.put|8 'i'|
test_map.put|9 'j'|
test_map.put|10 'k'|

test_map.set|6 'z'|

print|test_map|
print| test_map[0] test_map[1] test_map[2] test_map[3] test_map[4] test_map[5] test_map[6] test_map[7]
test_map[8] test_map[9] test_map[10]|
                                    print|"done"|