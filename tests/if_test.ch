x: int = 17

print|"starting"|

if true start
    print|"hello false"|
else-if (equal x 17) start
    
end


$
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
    if (equal str_data "hello world!!!-") start
        print|"successful check"|
    end
end

start 
    print|"done"|
end
$