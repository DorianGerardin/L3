1:

type form =
  | Top | Bot
  | Var of string
  | Not of form
  | And of form * form
  | Or of form * form
  | Imp of form * form
  | Equ of form * form;;
  
let f1 = Top;;
let f2 = Var "A";;
let f3 = And (Var "A", Var "B");;
...

2:

let rec print_form = function
    | Top -> print_string "T"
    | Bot -> print_string "⊥"
    | Var s -> print_string s
    | Not f-> print_string "("; print_string "¬"; print_form f; print_string ")"
    | And (f1, f2) -> print_string "("; print_form f1; print_string " ∧ "; print_form f2; print_string ")"
    | Or (f1, f2) -> print_string "("; print_form f1; print_string " V "; print_form f2; print_string ")"
    | Imp (f1, f2) -> print_string "("; print_form f1; print_string " → "; print_form f2; print_string ")"
    | Equ (f1, f2) -> print_string "("; print_form f1; print_string " ↔ "; print_form f2 ; print_string ")";;


3:

let simplif_and = function
| And (f, Top) | And (Top, f) -> f
| And (f,Bot) | And (Bot,f) -> Bot
| e -> e;;

let simplif_or = function
| Or (f,Top) | Or (Top,f) -> Top
| Or(f,Bot) | Or (Bot,f) -> f
| e -> e;;

let simplif_imp = function
| Imp(f,Top) -> Top
| Imp(Top,f) -> f
| Imp(f,Bot) -> Not f
| Imp(Bot,f) -> Top
| e -> e;;

let simplif_equ = function
| Equ(f,Top) -> f
| Equ(Top,f) -> f
| Equ(f,Bot) -> f
| Equ(Bot,f) -> f
| e -> e;;

let rec simplif_form = function
| And (f1, f2) ->
  let f1' = simplif_form f1
  and f2' = simplif_form f2 in
  simplif_and (f1', f2')
| Or (f1, f2) ->
  let f2' = simplif_form f1
  and f2' = simplif_form f2 in
  simplif_or (f1',f2')
| Imp (f1, f2) ->
  let f1' = simplif_form f1
  and f2' = simplif_form f2 in
  simplif_imp (f1', f2')
| Equ (f1, f2) ->
  let f1' = simplif_form f1
  and f2' = simplif_form f2 in
  simplif_equ (f1', f2')
| f -> f;;
