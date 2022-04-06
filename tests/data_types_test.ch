print|(+ (typeof 0) " " (typeof 0d) " " (typeof 0f) " " (typeof ' ') " " (typeof "") " " (typeof true) " " (typeof []) " " (typeof {}))|
print|"0 == int:" (equal (typeof 0) "int")|
print|"0d == double:" (equal (typeof 0d) "double")|
print|"0f == float:" (equal (typeof 0f) "float")|
print|"'c' == char:" (equal (typeof 'c') "char")|
print|"\"s\" == string:" (equal (typeof "") "string")|
print|"true == bool:" (equal (typeof true) "bool")|
print|"{} == map:" (equal (typeof {}) "map")|
print|"[] == list:" (equal (typeof []) "list")|