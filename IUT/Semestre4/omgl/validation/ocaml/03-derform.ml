(*****************************************************************************)
(*****************************************************************************)

(* On désire fabriquer une table associant des nombres à virgules flottantes à des chaînes de caractères. On codera une telle table à l'aide d'une liste de couples (chaine, nombre). Il nous faudra également une fonction de recherche et une fonction d'insertion. *)
  
type liststringfloat  = (string * float) list;;

let insert tbl str x = (str,x)::tbl;;

(* Q1 : commentez le type de la fonction insert, en particulier celui du paramètre tbl; 
modifiez sa definition de telle sorte que son type soit str2float_tbl -> string -> float -> str2float_tbl;
   a-t-on besoin de specifier le type des parametres str et x ? *)

type str2float_tbl = ( string * float ) ;;
type liststringfloat  = ( string * float ) list;;
let insert (tbl:liststringfloat) str x = (str,x)::tbl;;


(* Q2 : écrire la fonction de recherche 'search' dont le type doit être  search : str2float_tbl -> string -> float option  voir documentation pour le type 'option'. *)

let division x y =
  if (y = 0)
  then None
  else Some(x/y) ;;

let tab = [("BONJOUR",1.5);("ahah",4.0);("oui",3.9) ] ;;

let rec search (t:liststringfloat) x =
match t with
| [] -> None
| (s,f)::tt -> 
    if ( s = x ) then Some(f)
    else (search tt x) ;;

(search tab "ou");;
;;

(* Q3: le type option offre un moyen d'écrire proprement des fonctions
   partielles, le mécanisme des exceptions en est un autre (voir
   documentation), utilisez ce dernier pour ecrire une nouvelle
   version de la fonction search, cette fois-ci de type search :
   str2float_tbl -> string -> float *) 

exception NotFound of string;;

let rec search (t:liststringfloat) x =
match t with
| [] ->raise (NotFound x)
| (s,f)::tt -> 
    if ( s = x ) then f
    else (search tt x) ;;

let vi = [] ;;

(* Un autre concept fondamental est celui de type inductif. Il permet
   à l'utilisateur de définir de nouveaux types comme union de
   types. L'exemple suivant définit un nouveau type (recursif) qui
   code les expressions arithmétiques: *)

type expr =
    Const of float
  | Var of string
  | Sum of expr * expr
  | Diff of expr * expr
  | Prod of expr * expr
  | Quot of expr * expr;;

(* Q4: définir un élément de type expr qui code l'expression
   2x + 4y + 1 *)
let bino = Sum( Prod((Const 2.0),(Var "x")), Sum( Prod((Const 4.0),(Var "y") ), (Const 1.0) ) );;


(* Q5: que fait la fonction suivante (on utilise ici la dernière
version de search) ? *)

let rec eval tbl e =
  match e with
  | Const x -> x
  | Var id -> search tbl id
  | Sum (e1,e2) -> (eval tbl e1) +. (eval tbl e2) 
  | Diff (e1,e2) -> (eval tbl e1) -. (eval tbl e2)
  | Prod (e1,e2) -> (eval tbl e1) *. (eval tbl e2)
  | Quot (e1,e2) -> (eval tbl e1) /. (eval tbl e2)
;;

let tab = [("x",5);("y",4) ];;

(eval tab bino);;
;;

(* Q6: Commentez le warning emis par l'interpreteur, essayez cette
   fonction avec l'expression definie précédemment. Corrigez le code de
   eval pour eliminer le warning en question *)
	
(* Q7: ecrire une fonction qui calcule la dérivée d'une expression de
   type expr *)

let rec deriv e =
  match e with
    Const x -> x
  | Var id -> search tbl id
  | Sum(e1,e2) -> (deriv e1) + (deriv e2)
  | 

(* let rec derive id e = match e with     <==>    let rec derive id = Function *)

(*****************************************************************************)
(* Q8: integrez les fonctions exp(x) et ln(x) dans tous les
   traitements *)

(*****************************************************************************)
(* Q9 : écrire une fonction qui transforme une expression en une
   chaine de caractère lisible *)

let rec prettyprint e =
  match e with
  | Const x -> string_of_float x
  | Var id -> id
  | Sum (e1,e2) -> (prettyprint e1) ^ " + " ^ (prettyprint e2)
  | Diff (e1,e2) -> (prettyprint e1) ^ " - " ^ (prettyprint e2)
  | Prod (e1,e2) -> (prettyprint e1) ^ " . " ^ (prettyprint e2)
  | Quot (e1,e2) -> (prettyprint e1) ^ " / " ^ (prettyprint e2)
;;

let test = Sum( Prod((Const 2.0),(Var "x")), Sum( Prod((Const 4.0),(Var "y") ), (Const 1.0) ) );;

(prettyprint test);;

let simpl e =
match e with
  | Sum((Const 0.0),e1) | Sum(e1,(Const 0.0)) -> e1;;
  | Sum((Const a),(Const b)) -> Const(a+.b)
  | Sum
  | Prod((Const 1.0),e1) | Prod(e1, (Const 1.0) ) -> e1;;
  | Prod((Const 0.0),e1) | Prod(e1, (Const 0.0) ) -> Const 0.0;;
  | Prod((Const a),(Const b)) -> Const(0.0)

(*****************************************************************************)
(*****************************************************************************)
