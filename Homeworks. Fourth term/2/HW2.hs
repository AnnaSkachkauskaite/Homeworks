helper :: [a] -> [a] -> [a]
helper list [] = list
helper list(s:xs) = helper(s:list) xs

reverse' :: [a]->[a]
reverse' list = helper [] list

degreeList :: Integer -> [Integer]
degreeList n = [2^a | a <- [1..n]]

digitSum :: Integer -> Integer
digitSum 0 = 0
digitSum x = x `mod` 10 + digitSum (x `div` 10)

findPosition :: [Integer] -> Integer -> Integer
findPosition [] _ = 0
findPosition (x:xs) e
    | x == e    = 1
    | otherwise     = 1 + findPosition xs e

isPalindrome :: String -> Bool
isPalindrome s = s == reverse' s