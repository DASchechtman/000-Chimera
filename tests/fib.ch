(var cache:map {})

suro fib|int|: double start
    if (<= arg0 1) start
        return arg0
    end

    (var fib1:int (- arg0 1))
    (var fib2:int (- arg0 2))
    $    
    if (not cache.has|fib1|) start
        cache.put|fib1 (call fib fib1)|
    end
    if (not cache.has|fib2|) start
        cache.put|fib2 (call fib fib2)|
    end

    return (+ (get cache fib1) (get cache fib2) )
    $
    return (+ (call fib fib1) (call fib fib2))
end

suro fibLin|int|: double start
    if (<= arg0 1) start
        return arg0
    end

    (var fib1: double 0)
    (var fib2: double 1)
    (var res: double arg0)

    repeat (- arg0 1) with i start
        
            (= res (add fib1 fib2))
            (= fib1 fib2)
            (= fib2 res)
        
    end

    return res
end

repeat 100 with i start
    if true start
        print|i ':' (call fib i)|
    else start
        print|i ';' (call fibLin i)|
    end
end