predicates
	f(integer, integer, integer)
clauses
	f(A, B, 1):-
	C = A + B,
	write(C).
	f(A, B, 2):-
	C = A - B,
	write(C).
	f(A, B, 3):-
	C = A*B,
	write(C).
	f(A, B, 4):-
	C = A/B,
	write(C).
goal
	f(6, 4, 2)
