import Control.Monad
printhelper :: [Integer] -> IO ()
printhelper [] = return ()
printhelper [x] = print x
printhelper (x:xs) = do putStr $ show x; putStr " + "; printhelper xs

findSum :: Integer -> IO()
findSum n = helper n n []


helper :: Integer -> Integer -> [Integer] -> IO()
helper 0 m st =  printhelper st
helper n m st = 
		if (n < 0) then 
			return()
			else do 
				when (n - m >= 0) $ helper (n - m) m (m:st)
				when (m - 1 > 0) $ helper n (m - 1) st
				return ()