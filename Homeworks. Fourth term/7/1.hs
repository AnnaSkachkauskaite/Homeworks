import Control.Exception.Base

type PhoneBook = [(String, [String])]

findName :: String -> PhoneBook -> Maybe [String]
findName number book = case result of
	[] -> Nothing
	_ -> Just (map (fst) result)
	where result = filter (\(x,y) -> number `elem` y) book

addRecord :: (String, String) -> PhoneBook -> PhoneBook
addRecord (name, number) book = case (lookup name book) of
                        Just _ -> map (\(x,y) -> if x == name then (x, number:y) else (x,y)) book
                        Nothing -> (name, [number]):book


menu :: IO ()
menu = do
	putStrLn "0 - exit"
	putStrLn "1 name number - add record"
	putStrLn "2 name - find number"
	putStrLn "3 number - find name "
	putStrLn "4 file - save to file"
	putStrLn "5 file - read from file"


log' :: PhoneBook -> IO ()
log' book = do
    command <- getLine
    case (command !! 0) of
        '0' -> return ()
        '1' -> case (words $ drop 2 command) of
                [name, number] -> do log' (addRecord (name, number) book)
                _ -> fail "wrong number of arguments"
        '2' -> do case (words $ drop 2 command) of
                    [name] -> do putStrLn $ show (lookup name book); log' book
                    _ -> fail "wrong number of arguments"
        '3' -> do case (words $ drop 2 command) of
                    [number] -> do putStrLn $ show (findName number book); log' book
                    _ -> fail "wrong number of arguments"
        '4' -> do case (words $ drop 2 command) of
                    [filename] -> do writeFile filename (show book); log' book
                    _ -> fail "wrong number of arguments"
        '5' -> do
                file <- readFile (drop 2 command)
                newbook <- readIO file :: IO PhoneBook
                log' newbook
        _   -> fail $ "wrong command: " ++ command


main = do menu; log' []
                        



