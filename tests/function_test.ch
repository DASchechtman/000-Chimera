$
suro addInts|int int|: int start
    (= x:int (add arg0 arg1))
    print|"sum is" x|
end

(call addInts 5 10)

func foo|list|: int start
    arg0.set|0 80|
    print|arg0|
    return (get arg0 0)
end

(var x:list [true false "hello world"])
print|(call foo [1 2 3])|
print|x|
$

furo recurseTest|int| start
    if (greater-equal arg0 0) start
        print|arg0|
        (call recurseTest (- arg0 1))
    end
end

furo fib|seq_index: int| start
    (var ret: int seq_index)

    if (greater ret 1) start
        (var fib1: int (call fib (sub ret 1)))
        (var fib2: int (call fib (sub ret 2)))
        (= ret (add fib1 fib2))
    end

    return ret
end

#(call recurseTest (add 5 10))
print|(call fib 100)|
print|"done"|