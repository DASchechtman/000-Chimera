(var x:int 10)
start
    (var y:int<ref> x)
    (var z:int<ref> y)

    (var x:int 77)
    (= y x<ref>)

    start
        (var x:int 824)
        (= y x<ref>)

        start
            (var x:int 23892)
            (= y x<ref>)

            start
                print|y|
            end
        end
    end
end

print|"done:" 23892|
