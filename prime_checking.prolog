predicates
	go
	prime(integer,integer)
	check(integer,integer,integer)
clauses
	go:-
		write("enter no="),
		readint(X),
		prime(X,2).

	prime(A,A):-
		write("Prime").
		
	prime(A,B):-
		C= A mod B,
		check(A,B,C).
	
	
	check(,,0):-
		write("Not Prime").
	
	check(A,B,X):-
		BB=B+1,
		prime(A,BB).
		
goal
	go
