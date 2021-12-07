x: int = 18

print|"starting"|

if false start
    print|"hello false"|
else-if (equal x 18) start
    print|"x =" x|
else-if (less x 18) start
    print|"x is under 18"|
else-if (less x 19) start 
    print|"x is under 19"|
else start 
    print|"default"|
end

if false start
    print|"hello world and sun"|
else start
    print|"hello mars"|
end

start
    print|"clearing if stack"|
end


if (not-equal x (add x 1)) start
    if true start
        print|"nested if"|
        start
            print|"new scope" (mul x 2)|
        end
    end
    print|"hello world" x|
    y: int = 99
    print|"inside if" y|
end

if (greater x 18) start
    print|"hello mars"|
end

str_data: string = "hello world"

if (equal str_data "hello world!!!") start
    print|"finished last if"|
end

if (not-equal str_data "hello world!!!") start
    str_data = (add str_data "!!!")
    if (equal str_data "hello world!!!") start
        print|"successful check"|
    end
end

start 
    print|"done"|
end
