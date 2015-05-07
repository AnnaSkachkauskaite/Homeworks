import Test.HUnit

data Tree a = Leaf a | Branch (Tree a) a (Tree a)

searchTree :: (a -> Bool) -> Tree a -> [a]

searchTree p (Leaf l) = if p l then [l] else []

searchTree p (Branch left el right) = if p el then concat [[el], searchTree p left, searchTree p right]
											else concat [searchTree p left, searchTree p right]




testTree = Branch ( Branch (Leaf 1) 4 (Leaf (-1)) ) 1 ( Branch (Leaf 2) 3 (Leaf (-2)) )

test1 = TestCase $ assertEqual "x > 0" [1, 4, 1, 3, 2] $ searchTree (\x -> x > 0) testTree
test2 = TestCase $ assertEqual "abs" [2, -2] $ searchTree (\x -> abs x == 2) testTree

tests = TestList [TestLabel "test1" test1, TestLabel "test2" test2]
                                                
main = do
	   runTestTT tests