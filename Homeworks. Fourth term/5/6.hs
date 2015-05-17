import Test.QuickCheck

data Expression = X
				| Const Int
				| Expression :+: Expression
				| Expression :-: Expression
				| Expression :*: Expression
				| Expression :^: Int
				deriving (Eq, Show)


simplify :: Expression -> Expression
simplify expr = case expr of 
	(Const 0 :*: X) -> Const 0
	(X :*: Const 0) -> Const 0
	(Const 1 :*: X) -> X
	(X :*: Const 1) -> X
	(Const 0 :+: X) -> X
	(X :+: Const 0) -> X
	(X :^: 0) -> Const 1
	(X :^: 1) -> X
	(Const n1 :+: Const n2) -> Const (n1 + n2)
	(Const n1 :-: Const n2) -> Const (n1 - n2)
	(Const n1 :*: Const n2) -> Const (n1 * n2)
	(Const n1 :^: n2) -> Const (n1 ^ n2)
	_ -> expr


simplifyExpr :: Expression -> Expression
simplifyExpr expr = case expr of 
	X -> X
	(Const n) -> Const n
	(e1 :+: e2) -> simplify $ (simplifyExpr e1 :+: simplifyExpr e2)
	(e1 :-: e2) -> simplify $ (simplifyExpr e1 :-: simplifyExpr e2)
	(e1 :*: e2) -> simplify $ (simplifyExpr e1 :*: simplifyExpr e2)
	(e1 :^: n) -> simplify $ (simplifyExpr e1 :^: n)


derivate :: Expression -> Expression
derivate expr = case expr of
	X -> Const 1
	(Const n) -> Const 0
	(e1 :+: e2) -> (derivate e1 :+: derivate e2)
	(e1 :-: e2) -> (derivate e1 :-: derivate e2)
	(e1 :^: n) -> (Const n :*:(e1 :^: (n - 1)) :*: derivate e1)
	(e1 :*: e2) -> ((derivate e1 :*: e2) :+: (derivate e2 :*: e1))

derivateExpr :: Expression -> Expression
derivateExpr expr = simplifyExpr $ derivate expr

calc :: Expression -> Int -> Int
calc expr m = case expr of 
	(Const n) -> n
	X -> m
	(e1 :+: e2) -> (calc e1 m) + (calc e2 m)
	(e1 :-: e2) -> (calc e1 m) - (calc e2 m)
	(e1 :*: e2) -> (calc e1 m) * (calc e2 m)
	(e :^: n)   -> (calc e m) ^ n


expr1 = Const 3
expr2 = (X :^: 2) :+: X
expr3 = ((Const 3 :*: X) :+: (X :^: 1)) :*: (Const 1 :+: X)
expr4 = ((X :+: X) :*: (X :+: X) :*: (X :+: X))

dexpr1 = Const 0
dexpr2 = (Const 2 :*: X) :+: Const 1
dexpr3 = Const 4 :+: (Const 8 :*: X)
dexpr4 = (Const 24 :*: (X :*: X))

main = do
	quickCheck (\s -> calc (derivateExpr expr1) s == calc (simplifyExpr dexpr1) s)
	quickCheck (\s -> calc (derivateExpr expr2) s == calc (simplifyExpr dexpr2) s)
	quickCheck (\s -> calc (derivateExpr expr3) s == calc (simplifyExpr dexpr3) s)
	quickCheck (\s -> calc (derivateExpr expr4) s == calc (simplifyExpr dexpr4) s)