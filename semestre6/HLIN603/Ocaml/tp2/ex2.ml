class account b =
object (self)
	val mutable balance = 0.0
	method get = balance
	method deposit a = balance <- balance +. a
	method withdraw a = balance <- balance −. a
	method print = print_float balance ; print_newline( )
	initializer self#deposit b
end;;

class interest_account b =
object
	inherit account b
	method intereset =
		balance <- +. 5. *. balance /. 100.
end;;

class secure_account b =
object
	inherit account as super
	method withdraw a =
		if (balance -. a) >= 0. then super#withdraw a
		else failwith "Not enough money !"
end;;

1:

class bank = 
object (self)
	val mutable listAccounts = new [];;
	method add (a : account) = c :: listAccounts
	method balance = 
		List.fold_left(fun a b -> a +. b#get) 0. listAccounts
	method print = List.iter(fun a -> a#print) listAccounts
	method fees = List.iter(fun a -> a#withdraw(a#get * 0.05)) listAccounts
end;;

2:

class ['a] collection = 
        object (self)
        val mutable listAccounts = []
        method add (x : 'a) = listAccounts <- x :: listAccounts
end;;

class bank2 = 
object (self)
	inherit [account] collection
	method balance = 
		List.fold_left(fun a b -> a +. b#get) 0. listAccounts
	method print = List.iter(fun a -> a#print) listAccounts
	method fees = List.iter(fun a -> a#withdraw(a#get * 0.05)) listAccounts
end;;