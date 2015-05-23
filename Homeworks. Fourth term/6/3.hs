data BinaryTree a = Empty | Node a (BinaryTree a) (BinaryTree a) deriving (Eq, Show)



treeSize :: BinaryTree a -> Int
treeSize Empty = 0
treeSize (Node n left right) = 1 + (treeSize left) + (treeSize right)


height :: BinaryTree a -> Int
height Empty = 0
height (Node n left right) = (max (height left) (height right)) + 1



find :: (Ord a) => a -> BinaryTree a -> Bool
find _ Empty = False
find x (Node n left right) = 
	if x < n then (find x left)
		else if (x > n) then (find x right)
			else True


add :: (Ord a) => a -> BinaryTree a -> BinaryTree a
add x Empty = Node x Empty Empty
add x (Node n left right) = 
	if x < n then (Node n (add x left) right)
		else if (x > n) then (Node n left (add x right))
			else Node n left right

findMinElem :: (Ord a) => BinaryTree a -> a
findMinElem (Node n Empty right) = n
findMinElem (Node n left right) = findMinElem left

remove :: (Show a, Ord a, Eq a) => a -> BinaryTree a -> BinaryTree a
remove x Empty = Empty
remove x (Node y left right)
	| x > y = Node y left (remove x right)
	| x < y = Node y (remove x left) right
	| left == Empty = right
	| right == Empty = left
	| otherwise = Node (findMinElem right) left (remove (findMinElem right) right) 

tree = add 1 (add 7 (add 0 (add (-2) (add 9 (add 16 Empty)))))

main = do
		print tree
		print $ (height tree)
		print $ (treeSize tree)
		print $ show (remove 9 tree)
		print $ show (add 100 tree)
		