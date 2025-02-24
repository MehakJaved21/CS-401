(* Fold-left: processes the list from left-to-right.
   Combines the current accumulator with the current element.
   Example: myFoldl (+) 0 [1;2;3;4;5] = 15 *)
let rec myFoldl op acc lst =
  match lst with
  | [] -> acc
  | x::xs -> myFoldl op (op acc x) xs

(* Fold-right: processes the list from right-to-left.
   The operator receives the current element first, then the accumulated result.
   Example: myFoldr (+) [1;2;3;4;5] 0 = 15 *)
let rec myFoldr op lst acc =
  match lst with
  | [] -> acc
  | x::xs -> op x (myFoldr op xs acc)

(* Reverse without using folds:
   This tail-recursive version uses an accumulator to build the reversed list.
   Example: myReverse [1;2;3;4] = [4;3;2;1] *)
let rec myReverse ?(acc=[]) lst =
  match lst with
  | [] -> acc
  | x::xs -> myReverse ~acc:(x :: acc) xs

(* Reverse using fold-left:
   We accumulate by prepending each element, naturally reversing the list.
   Example: myReverseFold [1;2;3;4] = [4;3;2;1] *)
let myReverseFold lst =
  myFoldl (fun acc x -> x :: acc) [] lst

(* Map without using folds:
   This function applies 'op' to each element.
   We use an accumulator to gather results (in reverse order) then reverse the result.
   Example: myMap (fun x -> x + 1) [1;2;3;4] = [2;3;4;5] *)
let rec myMap ?(acc=[]) op lst =
  match lst with
  | [] -> List.rev acc
  | x::xs -> myMap ~acc:(op x :: acc) op xs

(* Map using fold-right:
   Using fold-right helps preserve the original order.
   Example: myMapFold (fun x -> x + 1) [1;2;3;4] = [2;3;4;5] *)
let myMapFold op lst =
  myFoldr (fun x acc -> (op x) :: acc) lst []

(* Filter without using folds:
   This function retains only the elements that satisfy the guard condition.
   We accumulate in reverse order and then reverse the accumulator.
   Example: myFilter (fun x -> x mod 2 = 0) [1;2;3;4] = [2;4] *)
let rec myFilter ?(acc=[]) guard lst =
  match lst with
  | [] -> List.rev acc
  | x::xs ->
      if guard x then myFilter ~acc:(x :: acc) guard xs
      else myFilter ~acc guard xs

(* Filter using fold-right:
   Using fold-right allows us to preserve the order naturally.
   Example: myFilterFold (fun x -> x mod 2 = 0) [1;2;3;4] = [2;4] *)
let myFilterFold guard lst =
  myFoldr (fun x acc -> if guard x then x :: acc else acc) lst []
