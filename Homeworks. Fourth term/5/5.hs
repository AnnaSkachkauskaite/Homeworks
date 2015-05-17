import Control.Monad

isFind :: (Ord a) => (a, a, a) -> Maybe a
isFind (m, n, l) = if (m < n && n > l) 
	then Just n
	else Nothing

find :: (Ord a) => [a] -> Maybe a
find [] = Nothing
find (m:n:l:list) = mplus (isFind(m, n, l)) (find(n:l:list))
