(var input_bucket: list [0])

suro ValidateInput|list string price:double|: bool start
    (var input (get_input arg1))
    (var right_data:bool (and (== (typeof input) (typeof 0d)) (> input price)))
    arg0.set|0 input|
    return right_data
end

func CalcCurrencyAmt|pennies:int bill_amt_in_p:double|: double start
    (var b_to_p:int bill_amt_in_p)
    (var possible_change:int (div pennies b_to_p))
    return (mul b_to_p possible_change)
end

suro UpdateChangeCalc|pennies:int amounts:list bill:double string| start
    (var calced:double (call CalcCurrencyAmt pennies bill))
    (= pennies (sub pennies calced))
    amounts.addTo|(div calced bill)|
    amounts.addTo|arg3|
end

func CalcChange|sales_price:double payment:double| start
    print|"The change due back is $" (- payment sales_price)|

    (var change_in_pennies: int (mul (sub payment sales_price) 100))
    (var cash_amounts: list [])

    # UpdateChangeCalc(change_in_pennies cash_amounts 100 * 100 "$100 bills")
    (call UpdateChangeCalc change_in_pennies cash_amounts (* 100d 100) "$100 bills")
    (call UpdateChangeCalc change_in_pennies cash_amounts (* 50d 100) "$50 bills")
    (call UpdateChangeCalc change_in_pennies cash_amounts (* 20d 100) "$20 bills")
    (call UpdateChangeCalc change_in_pennies cash_amounts (* 10d 100) "$10 bills")
    (call UpdateChangeCalc change_in_pennies cash_amounts (* 5d 100) "$5 bills")
    (call UpdateChangeCalc change_in_pennies cash_amounts 100d "$1 bills")
    (call UpdateChangeCalc change_in_pennies cash_amounts 25d "Quarters")
    (call UpdateChangeCalc change_in_pennies cash_amounts 10d "Dimes")
    (call UpdateChangeCalc change_in_pennies cash_amounts 5d "Nickles")
    (call UpdateChangeCalc change_in_pennies cash_amounts 1d "Pennies")

    (var i:int 0)
    while (< i cash_amounts.size) start
        print|(get cash_amounts i) (get cash_amounts (add i 1))|
        (= i (add i 2))
    end
end

$
(var sales_prompt:string "enter sales price: ")
(var purchase_prompt:string "enter price customer will pay: ")
(var valid_input:bool (call ValidateInput input_bucket sales_prompt 0d))
$

(var sales 20.38)
(var pay 123.77)

(var valid_sale:bool (call ValidateInput input_bucket "enter sale price $" 0d))
input_bucket.addTo|(get input_bucket 0)|
(var valid_pay:bool (call ValidateInput input_bucket "enter pay amount $" (get input_bucket 0)))

(= sales (get input_bucket 1))
(= pay (get input_bucket 0))

if valid_sale start
    if valid_pay start
        (call CalcChange sales pay)
    else start
        print|"error, customer didn't pay enough"|
    end
else start
    print|"error, item can't be free"|
end