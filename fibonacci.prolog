predicates
	go
	fibo(integer,integer,integer,integer)

clauses
	go:-
		write("enter no="),
		readint(X),
		nl,write("enter 1st position:"),
		readint(Y),
		write("0"),nl,
		fibo(0,1,X,Y).

	fibo(A,B,C,N):-
		N<C, write(B), nl, D=A+B,
		N1=N+1, fibo(B,D,C,N1).
goal
  go
