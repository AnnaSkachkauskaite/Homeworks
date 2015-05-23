import Control.Monad.State

data Tree = Empty | Node Char (Tree) (Tree) deriving (Eq, Show)

treeToStr :: Tree -> String
treeToStr Empty = "e"
treeToStr (Node x left right) = 'n' : x : (treeToStr left ++ treeToStr right)


strToTree :: String -> Tree
strToTree s = 
	let helper = do
							str <- get
							case (str) of
								('n' : ch : rest) -> do
														put rest
														l <- helper
														r <- helper
														return (Node ch l r)
								('e' : rest) -> do
													put rest
													return (Empty)
	in evalState helper s


tree = Node 'q'
			(Node 'w'
				Empty
				(Node 'e'
					Empty
					Empty
				)
			)
			Empty

main = do
	putStrLn (treeToStr tree)
	print $ show ( (strToTree . treeToStr) tree)