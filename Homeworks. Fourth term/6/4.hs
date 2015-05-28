import Control.Monad.State
import Test.QuickCheck

data Graph v e = Graph [(Int,v)] [(Int,Int,e)]

inf = maxBound :: Int


helpermin :: [(Int, Int)] -> (Int, Int) -> (Int, Int)
helpermin [] m = m
helpermin ((m,n):l) (m1,n1) = if n < n1
    then helpermin l (m, n)
    else helpermin l (m1, n1)

minInList :: [(Int, Int)] -> (Int, Int)
minInList (l:ls) =  helpermin ls l



change :: [(Int, Int)] -> (Int, Int) -> [(Int, Int)]
change e (m, n) = map (\(x, y) -> if (x == m) then (m, n) else (x, y)) e




dijkstra' :: [(Int,Int)] -> [(Int,Int,Int)] -> Int -> [(Int, Int)]
dijkstra' v e start
    | length v == 1 = v
    | otherwise  = case (lookup start v) of
                    Just mark -> let helper ((f, t, c):es)
                                        | start == f = do
                                            tovisit <- get
                                            case (lookup t tovisit) of
                                                Just m  -> if m < (mark + c)
                                                               then helper es
                                                               else do
                                                                    put $ change tovisit (t, mark + c)
                                                                    helper es
                                                Nothing -> helper es
                                        | otherwise  = helper es
                                     helper [] = return []
                                 in
                                 let newV = filter (\(x,y) -> x /= start) (execState (helper e) v) in
                                 (minInList v):(dijkstra' newV e (fst (minInList newV)))
                    Nothing -> error "No such vertex"

                                
dijkstra :: Graph v Int -> Int -> [(Int, Int)]
dijkstra (Graph v e) start = dijkstra' (map (\(x,y) -> if x == start then (x, 0) else (x, inf)) v) e start




testgraph = Graph [(0, 0), (1, 0), (2, 0)] [(0,1,7), (1,2,1), (0,2,20)] :: Graph Int Int

main = quickCheck (dijkstra testgraph 0 == [(0,0), (1,7), (2,8)])