(var t:char 'a')

suro foo|int|: int start
    repeat arg0 with i start
         print|"in func:" i t|
    end
end

repeat 10 with i start
    print|"in loop"|
    (call foo (add i 1))
end