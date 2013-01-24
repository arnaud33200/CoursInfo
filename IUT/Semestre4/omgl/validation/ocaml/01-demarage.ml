(*Q3/*)
let carre_float x y = dist(x y);;


let rec fact n = if n=0 then 1 else n * fact(n-1);;

(*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*)
Q4/
let rec fibbo =       
    function
    | 0 -> 1
    | 1 -> 1
    | n -> (fibbo (n-1)) + (fibbo (n-2));;


taille liste :
let rec taille l =
if l = [] then 0
else ( taille(List.lt l)) +1;;

(*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*)
(*Q5/*)
let rec insert n l =
match l with
| [] -> [n]
| x::ll -> 
if n > x then x::(insert n ll) 
else n :: l
;;

(*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *)
(*Q6/*)
let rec trier l =
match l with
| [] -> []
| x::ll -> (insert(trier ll) x) 


(*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*)
(*Q7/*)
Let rec contientposit l =
match l with
| [] -> false
| x::ll -> 
	if x > 0 then true
	else (contientposit ll) ;;

(*----- solution prof ------- *)

let positif x = ( x >= 0 );;

let rec existe f l =
   match l with
   [] -> false
   | x::l' -> 
       if (f x) then true 
       else existe f l';;

let existe_positif = existe positif ;;

(* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *)
(* Q8 /*)

let tab = [2;6;7;9;1;4;9] ;;
let addition a b = a + b ;;
List.fold_left addition 0 tab;;

(* ---- definition locale ------ *)

let add a b = a + b in fold_left add 0

let chainecaract = ["H";"E";"L";"L";"O"] ;;
let chainecaract = ["f";"z";"e";"f";" ";"z";"e";"f";"z";"e";" ";"f";"g";"z";"e";"r";"f";"g";"z";"e";] ;;
let conca a b = a ^ b ;;
List.fold_left conca "" chainecaract ;;
