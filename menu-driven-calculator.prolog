predicates
	go
	operation(integer,integer,integer)
clauses
	go:-
		write("Print X:"),
		readint(X),
		write("Print Y:"),
		readint(Y),
		write("Add:1, Sub:2, Mul:3:"),
		readint(P),
		operation(X,Y,P).
	operation(A,B,1):-
		C=A+B,
		write(C).
	operation(A,B,2):-
		C=A-B,
		write(C).	
	operation(A,B,3):-
		C=A*B,
		write(C).
goal	
	go
