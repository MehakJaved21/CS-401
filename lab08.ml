type 'a linetree =
  | Empty
  | Covered
  | LineTree of {
      start: float;
      end_: float;
      left: 'a linetree;
      right: 'a linetree;
    }

let shuffle lst =
  let nd = List.map (fun c -> (Random.bits (), c)) lst in
  let sond = List.sort compare nd in
  List.map snd sond

let rec insertLine tree (a, b) =
  if a >= b then tree (* Ignore invalid or zero-length lines *)
  else match tree with
    | Empty -> LineTree { start = a; end_ = b; left = Empty; right = Empty }
    | Covered -> Covered
    | LineTree { start; end_; left; right } ->
      if b < start then LineTree { start; end_; left = insertLine left (a, b); right }
      else if a > end_ then LineTree { start; end_; left; right = insertLine right (a, b) }
      else (* Merge overlapping segments *)
        let new_start = min a start in
        let new_end = max b end_ in
        LineTree { start = new_start; end_ = new_end; left; right }

let rec sumLineTree tree =
  match tree with
  | Empty -> 0.
  | Covered -> infinity
  | LineTree { start; end_; left; right } ->
    (end_ -. start) +. sumLineTree left +. sumLineTree right

let lineCoverage lines =
  let shuffled_lines = shuffle lines in
  let tree = List.fold_left insertLine Empty shuffled_lines in
  sumLineTree tree

(* Test Cases *)
let run_tests () =
  let test_cases = [
    ([], 0.);
    ([(1.,2.); (2.,3.); (4.,10.); (8.,12.); (50.,100.); (-100.,-50.)], 110.);
    ([(2., 1.); (5000., 5000.); (5., 5.); (100., 99.); (99., 0.); (infinity, neg_infinity)], 0.);
    ([(0., 1.); (4., 5.); (neg_infinity, 0.); (102321., 4000000.)], infinity);
    ([(1.12312341, 2.12398719823); (2.1231234, 3.); (3.12312451, 100.12312412341); (98.1231231, 123.12312410054525)], 121.876876180545253)
  ] in
  List.iter (fun (input, expected) ->
    let result = lineCoverage input in
    assert (abs_float (result -. expected) < 1e-6)
  ) test_cases;
  print_endline "All test cases passed!"

let () = run_tests ()
