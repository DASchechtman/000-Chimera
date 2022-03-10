(= res_msg: string "result: ")

# add operator test
print| "should: 10" (+ res_msg (cast (+ 5 5) string)) |
print| "should: 12" (+ res_msg (cast (+ 5 5 2) string)) |

# minus operator test
print| "should: -7" (+ res_msg (cast (- 0 7) string)) |
print| "should be: 23" (+ res_msg (cast (- 45 5 10 5 2) string)) |

# multiply operator test
print| "should: 125" (+ res_msg (cast (* 5 5 5) string)) |
print| "should: 3.2" (+ res_msg (cast (* 10.0f .32f) string)) |

# divide operator test
print| "should: 2" (+ res_msg (cast (/ 4 2) string)) |
print| "should: 25" (+ res_msg (cast (/ (^ 5 3) 5) string)) |

# pow operator test
print| "should: 125" (+ res_msg (cast (^ 5 3) string)) |
print| "should: 256" (+ res_msg (cast (^ 2 8) string)) |

# less oper test
print| "5 < 6:" (less 5 6) |
print| "(should be false) 5 < 'hello world':" (less 5 "hello world") |

# all compare opers test
print| "5 > 3:" (greater 5 3) |
print| 
    "5 > true :" (greater 5 true) '\n'
    "5 < false :" (less 5 false) '\n'
    "5 >= true :" (greater-equal 5 true) '\n'
    "5 <= false :" (less-equal 5 false) '\n'
    "5 == true :" (equal 5 true) '\n'
|

$ logical operation test $
print| "hello and world and 5:" (and "hello" (and "world" 5)) |
print| "hello and world and 0" (and "hello" (and "world" 0)) |
print| "hello or (world and 0):" (or "hello" (and "world" 0)) |
print| "not (hello and world and 5):" (not (and "hello" (and "world" 5))) |