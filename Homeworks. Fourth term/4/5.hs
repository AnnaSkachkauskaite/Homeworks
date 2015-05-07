import Control.Monad
import Data.List
import Data.Int

add :: Int -> [Int] -> [Int]
add a [] = [a]
add a (x : xs) = if (a <= x) then  a : x : xs
					else x : (add a xs)


del :: Int -> [Int] -> [Int]
del a [] = []
del a (x : xs) = if (a == x) then  xs
					else x : (del a xs)

menu :: IO ()
menu = 
	putStr "0 - exit\n"
	putStr "1 - add value to sorted list\n"
	putStr "2 - remove value from list\n"
	putStr "3 - print list\n"
	putStr "4 - help\n"

commands :: [Int] -> IO ()
commands l = do
			line <- getLine
			let q = map (read :: String -> Int) $ words line

			let [a, b] = case (length q) of
							2 -> q
							1 -> [(q !! 0), (q !! 0)]

			case a of
				0 -> return ()
				1 -> commands (add b l)
				2 -> commands (del b l)
				3 -> do
						putStrLn $ show l 
						commands l
				4 -> do
						menu
						commands l

main = do
		menu
		commands []
	