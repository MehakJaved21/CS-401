(* Non-tail recursive Fibonacci function *)
let rec fib n =
  if n <= 0 then 0
  else if n = 1 then 1
  else fib (n - 1) + fib (n - 2)

(* Tail-recursive Fibonacci function *)
let rec fibTail ?(a=0) ?(b=1) n =
  if n <= 0 then a
  else if n = 1 then b
  else fibTail ~a:b ~b:(a + b) (n - 1)

(* Test the functions *)
let () =
  let n = 10 in
  Printf.printf "Non-tail recursive fib(%d) = %d\n" n (fib n);
  Printf.printf "Tail-recursive fibTail(%d) = %d\n" n (fibTail n)

