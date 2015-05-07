
import Test.QuickCheck

countMap = sum . map (\x -> mod (x + 1) 2) 
countFoldr = foldr (\x y -> (x + 1) `mod` 2 + y) 0
countFilter = length . filter (\x -> mod x 2 == 0) 

help :: Int -> Int -> Int -> Int -> Bool
help a b c d = a == b && b == c && c == d

main = do
       quickCheck (\s -> let l = [0 .. abs s] 
    				     in help (countMap l) (countFoldr l) (countFilter l) ((abs s) `div` 2 + 1))