(var global_val: string "hello global")

suro fib|index: int| start
    if (less index 2) start
        return index
    end
    return (+ (call fib (- index 1)) (call fib (- index 2)) )
end

start
    (var semi_global_val: string "hello semi-global")
    func test|| start
        (var local_val: string "hello local")
        print|global_val|
        print|semi_global_val|
        print|local_val|
    end

    (call test)

    repeat 100 with index start 
        print|index ':' (call fib index)|
    end
end