step (a,b) = (b, a+b)
fib n = fst (iterate step (0,1) !! n)