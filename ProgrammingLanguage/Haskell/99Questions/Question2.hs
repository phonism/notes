-- Method 1
myButLast :: [a] -> a
myButLast = last . init

-- Method 2
myButLast' x = reverse x !! 1

-- Method 3
myButLast'' x = x !! (length x - 2)

-- Method 4
myButLast''' [x,_] = x
myButLast''' (_:xs) = myButLast''' xs

-- Method 5
myButLast'''' (x:(_:[])) = x
myButLast'''' (_:xs) = myButLast'''' xs

-- Method 6
myButLast''''' = head . tail . reverse
