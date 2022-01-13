x: int = 1
s: string = "x ="
sum: int = 0
sum_output: string = "sum ="

while (not-equal x 0) start
    if (equal x (pow 10 4)) start
        x = (mul x -1)
        print|s x sum_output sum|
    else start
        print|s x sum_output sum|
    end

    sum = (add sum x)
    x = (add x 1)
end

# comment comment comment
ss: string = ",------,"

print|(add s ss) x|
print|"program is done!!!<---->"|
