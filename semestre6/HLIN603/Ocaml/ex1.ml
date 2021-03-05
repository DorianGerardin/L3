1:

let rec inverser_liste = function 
| []->[]
| t :: r -> (inverser_liste r) @ [t];;


2:

let rec occ n = function 
| [] -> 0 
| e::tl -> if e==n then 1+(occ n tl) else (occ n tl) ;;


3:

let rec estTriee = function
| [] | [_] -> true
| h::s::tl -> (h <= s) && (estTriee (s::tl));;


4:

let rec insertionTriee n = function
| [] -> [n]
| h::tl -> if(n <= h) then n::h::tl
		   else h::(insertionTriee n tl);;


5:

let rec tri = function
  |[] -> []
  |e :: tl -> insertionTriee e (tri tl);;
