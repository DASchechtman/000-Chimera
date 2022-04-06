# x: int = 1
(var x: int 1)

# s: string = "x ="
(var s: string "x =")

# sum: int = 0
(var sum: double 0)

# sum_output: string = "sum ="
(var sum_output: string "sum =")

while (not-equal x 0) start
    if (equal x (pow 10 8)) start
        # x = (mul x -1)
        (= x (mul x -1))
        print|s x sum_output sum|
    else start
        print|s x sum_output sum|
    end

    # sum = (add sum x)
    (= sum (add sum x))

    # x = (add x 1)
    (= x (add x 1))
end

# comment comment comment
# ss: string = ",------,"
(var ss: string ",----!--,")

print|(add s ss) x|
print|"program is done!!!<---->"|
