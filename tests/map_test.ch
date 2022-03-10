(= test_map:map {})
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
print| 
    (get test_map 0) 
    (get test_map 1) 
    (get test_map 2) 
    (get test_map 3) 
    (get test_map 4) 
    (get test_map 5) 
    (get test_map 6) 
    (get test_map 7)
    (get test_map 8) 
    (get test_map 9) 
    (get test_map 10)
|
print|"done"|