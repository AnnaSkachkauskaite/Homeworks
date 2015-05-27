import Test.QuickCheck

newtype Polynomial = Polynomial [Int] deriving (Eq)



sign :: Int -> String
sign x = if (x > 0)
			then "+"
			else ""

help :: Int -> Int -> String
help 0 n = ""
help x 0 = show x
help x 1 = if (x == 1) then "+X" else if (x == -1) then "-X" else sign x ++ show x ++ "X"
help x n = if (x == 1) then "+X^"  ++ show n else if (x == -1) then "-X^"  ++ show n else sign x ++ show x ++ "X^" ++ show n


removeplus :: String -> String
removeplus ('+':xs) = xs
removeplus s = s

instance Show Polynomial where
	show (Polynomial l) = removeplus $ getShow l 0 
					where
						getShow [] n = ""
						getShow (x : xs) n = help x n ++ getShow xs (n + 1)





calc :: Polynomial -> Int -> Int
calc (Polynomial p) v = calc' p 0
						where
							calc' [] n = 0
							calc' (x : xs) n = (v^n) * x + calc' xs (n + 1)


sum' :: [Int] -> [Int] -> [Int]
sum' [] p = p
sum' p [] = p
sum' (x : xs) (y : ys) = (x + y) : sum' xs ys

findSum :: Polynomial -> Polynomial -> Polynomial
findSum (Polynomial p1) (Polynomial p2) = Polynomial (sum' p1 p2)


minus' :: [Int] -> [Int] -> [Int]
minus' [] [] = []
minus' p [] = p
minus' [] (x : xs) = -x : (minus' [] xs)
minus' (x : xs) (y : ys) = (x - y) : minus' xs ys

minus :: Polynomial -> Polynomial -> Polynomial
minus (Polynomial p1) (Polynomial p2) = Polynomial (minus' p1 p2)


makeFull :: Int -> [Int] -> [Int]
makeFull n l
	| n > length l = l ++ (take (n - length l) (repeat 0))
	| otherwise = take n l

mult :: Polynomial -> Polynomial -> Polynomial
mult (Polynomial p1) (Polynomial p2)= Polynomial [sum $ zipWith (*) (makeFull n p1) (reverse $ makeFull n p2) 
							| n <- [1..(length p1 + length p2)]]





ex = Polynomial [0,1,-1,0,3,1] 
    					
main = do
    print $ show ex
    print $ calc ex 1
