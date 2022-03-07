suro fazz|int|: int start
    print|"param in func 3 is:" arg0|
end

suro bar|num: int|: int start
    print|"param in func 2 is:" num|
    fazz|(add num 1)|
end

suro foo|num: int|: int start
    print|"param in func 1 is:" num|
    bar|(add num 1)|
end

suro addNums|int int|: int start
    (= x:int arg0)
    (= y:int arg1)
    (add x y)
    print|"x + y =" x|
end


repeat 10 with i start
    (= z:int 5)
    (= b:int 10)
    addNums|z b|
    print|""|
end