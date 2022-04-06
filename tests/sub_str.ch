suro subStrAt|string int|:string start
    (var sub_val: string "")
    (var i:int arg1)

    while (< i arg0.size) start
        (var str_char:string (cast (get arg0 i) string))
        (= sub_val (add sub_val str_char))
        (inc i)
    end
    return sub_val
end

suro subStrBetween|string int int|:string start
    (var sub_val: string "")
    (var i:int arg1)

    while (<= i arg2) start
        (var str_char:string (cast (get arg0 i) string))
        (= sub_val (add sub_val str_char))
        (inc i)
    end
    return sub_val
end

print|(call subStrAt "hello world" 2)|
print|(call subStrBetween "hello world" 2 "hello world".size)|