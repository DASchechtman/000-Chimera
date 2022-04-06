
print|"suro function test"|
start
    (var x: int 10)
    (var c: char 't')
    (var l: list [0])
    suro mutateIntListAndChar|int char list|: string start
        (= arg0 88)
        (= arg1 'b')
        arg2.set|0 {|"hello" 'b'| }|
        return (+ "hello " (cast arg0 string) " and " (cast arg1 string) " and " (cast arg2 string))
    end
    print|(call mutateIntListAndChar x c l)|
    print|x c l "\n"|
end


print|"furo function test"|
start
    (var x: int 10)
    (var c: char 't')
    (var l: list [0])
    furo CantmutateIntListAndChar|int char list|: string start
        (= arg0 88)
        (= arg1 'b')
        arg2.set|0 {|"hello" 'b'| }|
        return (+ "hello " (cast arg0 string) " and " (cast arg1 string) " and " (cast arg2 string))
    end
    print|(call CantmutateIntListAndChar x c l)|
    print|x c l "\n"|
end

print|"func function test"|
start
    (var x: int 10)
    (var c: char 't')
    (var l: list [0])
    func onlyMutateContainers|int char list|: string start
        (= arg0 88)
        (= arg1 'b')
        arg2.set|0 {|"hello" 'b'| }|
        return (+ "hello " (cast arg0 string) " and " (cast arg1 string) " and " (cast arg2 string))
    end
    print|(call onlyMutateContainers x c l)|
    print|x c l "\n"|
end