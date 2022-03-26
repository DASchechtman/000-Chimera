(var item_costs:list [1.25 5 3.27 19.13 4.55 18.73])
(var total:float 0)

repeat item_costs.size with i start
    (= total (add total (get item_costs i)))
end

(var pennies:float (mul total 100))

(var dollars:int 0)
(var quarters:int 0)
(var dime:int 0)
(var nickle:int 0)
(var penny:int 0)

suro Reduce|float int int|: int start
    (var d:int (div arg0 arg2))
    (= arg1 d)
    (= arg0 (sub arg0 (mul d arg2)))
end

suro GetDollars|float int|: int start
    if (greater-equal arg0 100) start
        (call Reduce arg0 arg1 100)
    end
end

suro GetQuarters|float int|: int start
    if (greater-equal arg0 25) start
        (call Reduce arg0 arg1 25)
    end
end

suro GetDimes|float int|: int start
    if (greater-equal arg0 10) start
        (call Reduce arg0 arg1 10)
    end
end

suro GetNickles|float int|: int start
    if (greater-equal arg0 5) start
        (call Reduce arg0 arg1 5)
    end
end

suro GetPenny|float int|: int start
    (call Reduce arg0 arg1 1)
end

(var change:list [])

(call GetDollars pennies dollars)
change.addTo|["Dollars:" dollars]|

(call GetQuarters pennies quarters)
change.addTo|["Quarters:" quarters]|

(call GetDimes pennies dime)
change.addTo|["Dimes:" dime]|

(call GetNickles pennies nickle)
change.addTo|["Nickles:" nickle]|

(call GetPenny pennies penny)
change.addTo|["Pennies:" penny]|

print|'\n' change '\n'|