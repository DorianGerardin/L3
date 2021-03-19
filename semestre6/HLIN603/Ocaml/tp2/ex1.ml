1:

class min (xi : int) =
object (self)
  val mutable x = xi
  method get = x
  method set n = x <- n
  method min y = if self#get < y then self#get else y
end;;

class min_zero xi =
object
  inherit min xi
  method get = 0
end;;

let o1 = new min 4;;
-> val o1 : min = <obj>

let o2 = new min_zero 4;;
-> val o2 : min_zero = <obj>

o1#min 2;;
- : int = 2

o1#min 7;;
- : int = 4

o2#min 2;;
- : int = 0

o2#min (-2);;
- : int = -2
