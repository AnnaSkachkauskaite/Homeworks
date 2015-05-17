findSum :: Int -> IO()
findSum n = helper n 1 (concat[show(n), " = "])


helper :: Int -> Int -> String -> IO()
helper 0 m st = putStrLn(st)
helper n m st = if (n == m) then 
	helper 0 m (concat[st, show(n)])
	else 
		if (n < m) then 
			return()
			else do 
				helper (n - m) m (concat[st, show(m), " + "])
				helper n (m + 1) st
				return ()
                           
