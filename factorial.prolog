predicates
	go
	fact(integer,integer)
clauses
	go:-
	write("give the no:"),
	readint(X),
	Z=1,
	fact(X,Z).
	
	fact(1,Z):-
	write("the result:",Z).
	
	fact(X,Z):-
	Y=Z*X,
	XX=X-1,
	fact(XX,Y).
goal
  go
