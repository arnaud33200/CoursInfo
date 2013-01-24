(*****************************************************************************)
(*****************************************************************************)

type crambe =
  | Cerise of int
  | Branche of crambe * crambe ;; 

let a = Branche ( Branche( Cerise 1, Cerise 5 ), Branche( Cerise 7, Cerise 8 ) ) ;;

let rec listemoilesceriseplease t =
match t with
| Cerise n -> [n]
| Branche( c1, c2 ) ->
    ( listemoilesceriseplease c1 ) @ ( listemoilesceriseplease c2 ) ;;

listemoilesceriseplease a ;;


(* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *)
(* Q1: écrire une fonction qui calcule le nombre de noeuds d'un arbre *)

let rec taillearbre t =
match t with
| Cerise _ -> 0
| Branche( c1 , c2 ) ->
    ( taillearbre c1 ) + 1 + ( taillearbre c2 ) ;;

taillearbre a ;;    

(* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *)
(* Q2: écrire une fonction qui calcule la hauteur d'un arbre *)

let maxint a b =
if ( a > b )
then a
else b ;;

let rec hauteurarbre t =
match t with
| Cerise n -> 0
| Branche( c1, c2 ) -> 1+(maxint (hauteurarbre c1) (hauteurarbre c2) ) ;;

hauteurarbre a ;;
hauteurarbre b ;;

(* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *)
(* Q3: ajoutez des étiquettes aux noeuds internes et réécrire les
fonctions en conséquences *)

type crambe =
  | Cerise of int
  | Branche of int * crambe * crambe ;;

let b = Branche( 1, Branche(21, Cerise 1, Cerise 5), 
		  Branche( 22, 
		  Branche( 31, Cerise 1, Cerise 5), Branche(32, Cerise 1, Cerise 5) ) ) ;;

let rec taillearbre t =
match t with
| Cerise _ -> 0
| Branche(_, c1 , c2 ) ->
    ( taillearbre c1 ) + 1 + ( taillearbre c2 ) ;;

taillearbre b ;;

(* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *)
(* Q4: écrire une fonction qui à partir d'un arbre donné, construit un
   nouvel arbre obtenu en conservant la même forme, mais en ajoutant 1
   à toutes les étiquettes. *)

let rec constarbre t =
match t with
| Cerise m -> Cerise(m+1)
| Branche( n, c1, c2 ) -> Branche( n+1, (constarbre c1), (constarbre c2) ) ;;

constarbre b ;;


(*****************************************************************************)
(*****************************************************************************)
(* question sup *)

type megatree =
  | Stick of int * (megatree list) ;;

let ma = Stick( 1,[Stick(4,[(Stick 1,[]);(Stick 2, []) ])]);;
		 

let listarbre 

let rec listmega t =
match t with
| Leaf n -> [n]
| Stick( m, l) -> [m ] @ [ (listmega l ) ] ;;
