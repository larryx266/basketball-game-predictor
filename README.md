# baskitbal

typing make compiles into 'build' folder and creates executable 
named 'besgitbol' in 'bin' folder

to run, type ./bin/besgitbol "Milwaukee Buck.txt" "randomFileName.txt"

should spit out player's aggregated stats, and dump those same players from
the hashtable to make sure the hashtable's not messing things up

meant to be an intermediate testing file to make sure everything is functional 
and connected

make clean to delete 'build' and 'bin' directories 

note: current hash function only gives relatively unique hashes up to 36 letters

current roadmap: sum aggregates and compare between teams to get predicted winner
-> use a linear regression model to better estimate player stats from average