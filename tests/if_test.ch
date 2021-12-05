x: int = 17

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

$
if (greater x 18) start
    print|"hello mars"|
end

start
    print|"finished last if"|
end
$