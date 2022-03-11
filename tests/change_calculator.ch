(= item_costs:list [1.25 5 3.27 19.13 4.55])
(= total:float 0)

repeat item_costs.size with i start
    (= total (add total (get item_costs i)))
end

(= pennies:int (mul total 100))

(= dollars:int 0)
(= quarters:int 0)
(= dime:int 0)
(= nickle:int 0)
(= penny:int 0)

suro GetDollars|total:float int|: int start
    if (greater-equal total 100) start
        (= d:int (div total 100))
        (= arg1 d)
        (sub total (mul d 100))
    end
end

(call GetDollars pennies dollars)
print|pennies dollars|