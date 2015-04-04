isCorrect :: [Char] -> Bool
isCorrect x = isCorrect' x []

isCorrect' :: [Char] -> [Char] -> Bool
isCorrect'  [] x = (length x) == 0
isCorrect' ('(' : l1) l2 = isCorrect'  l1 ('(' : l2)
isCorrect' ('{' : l1) l2 = isCorrect'  l1 ('{' : l2)
isCorrect' ('[' : l1) l2 = isCorrect'  l1 ('[' : l2)

isCorrect'  (')' : l1) ('(' : l2) = isCorrect'  l1 l2
isCorrect'  ('}' : l1) ('{' : l2) = isCorrect'  l1 l2
isCorrect'  (']' : l1) ('[' : l2) = isCorrect'  l1 l2

isCorrect'  _ _ = False
