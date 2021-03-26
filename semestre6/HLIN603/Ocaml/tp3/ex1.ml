1)
class min ( init : int) =
  object(self)
    val x = init
    method get = x
    method min y = if self#get < y then self#get else y
end;;

class min_max ( init : int ) =
  object ( self )
    inherit min init
    method max y = if self#min y = y then self#get else y
end;;

class other =
  object
    method get = 1
    method min n = n-1
    method max n = n+1
  end;;

class ['a] cell ( init : 'a ) =
  object
    val mutable cont = init
    method get = cont
    method set n = cont <- n
  end;;


let natural(o:min) = o#min(0) = 0;;
(* min -> bool
o doit être un objet de type min ou identique a min *)

let negative ( o : #min ) = o#min(0) = o#get ;;
(* #min -> bool
En écrivant #min on dit que o doit contenir au 
moins toutes les méthodes de min avec les memes types et
eventuellemnt d'autres méthodes en plus *)

let positive o = o#get > 0 ;;
(* <get : int, …> -> bool
Donc o doit contenir au moins une fonction get qui 
renvois un int *)

let m = new min 1 ;;
let mm = new min_max 2 ;;
let o = new other ;;
let c = new cell 1 ;;
2)

natural m;; 
- : bool = true
m est de type min = < get : int; min : int -> int >
Donc pas de problème de typage.
o#min(0) rend 0, donc natural rend true.

natural mm;;
Error : mm est de type min_max
On attend des objets qui ont exactement le type de min.
Ici min_max rajoute la méthode max.

natural o;;
Error : erreur de typage, type de lobjet attendu : min, type de lobjet passé en paramètre : other
On attend des objets qui ont exactement le type de min.
Ici other rajoute la méthode max.

natural ( o :> min );; 
: bool = false
Typage : other est bien un sous-type de min (on retrouve toutes les méthodes de min dans other avec les mêmes types).
o#min(0) renvoie -1
Et -1 nest pas égal à 0

natural c;;
Erreur de typage : 
c est de type int cell = <get : int; set : int -> unit > et ce nest pas compatible avec min = <get : int; min : int -> int>
Il manque la méthode min à c.

negative m;;
- : bool = false
Pas derreur de typage car on attend un objet de type 'au moins' min.

negative mm;;
- : bool = false
Pas d'erreur de typage
mm est de type min_max, et contient toutes les méthodes de min, au moins (type ouvert dans negative). 

negative o;;
- : bool = false
Pas d'erreur de typage
o est de type other, et contient toutes les méthodes de min, au moins (type ouvert dans negative). 

negative c;;
Erreur de typage :
c est de type int cell = <get : int; set : int -> unit > et ce nest pas compatible avec min = <get : int; min : int -> int>
Il manque la méthode min à c.

positive m;;
- : bool = true
Pas d'erreur de typage
m est de type min = <get :int; min : int -> int>
ce qui est compatible avec le type ouvert attendu par la fonction : <get : int; .. >


positive mm;;
- : bool = true
Pas d'erreur de typage
mm est de type min_max = <get :int; min : int -> int; max : int -> int>
ce qui est compatible avec le type ouvert attendu par la fonction : <get : int; .. >


positive o;;
- : bool = true
Pas d'erreur de typage
o est de type other = <get :int; min : int -> int; max : int -> int>
ce qui est compatible avec le type ouvert attendu par la fonction : <get : int; .. >

positive c;;
- : bool = true
Pas d'erreur de typage
c est de type cell = <get :int; set : int -> unit>
ce qui est compatible avec le type ouvert attendu par la fonction : <get : int; .. >