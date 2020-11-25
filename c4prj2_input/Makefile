main: main.o input.o future.o eval.o deck.o cards.o
	gcc -o main main.o deck.o future.o eval.o input.o cards.o
main.o: main.c input.h future.h eval.h deck.h cards.h
	gcc -std=gnu99 -g -ggdb3 -pedantic -Wall -Werror -c main.c
input.o: input.c future.h eval.h deck.h cards.h
	gcc -std=gnu99 -g -ggdb3 -pedantic -Wall -Werror -c input.c
future.o: future.c eval.h deck.h cards.h
	gcc -std=gnu99 -g -ggdb3 -pedantic -Wall -Werror -c future.c
eval.o: eval.c deck.h cards.h
	gcc -std=gnu99 -g -ggdb3 -pedantic -Wall -Werror -c eval.c
deck.o: deck.c cards.h
	gcc -std=gnu99 -g -ggdb3 -pedantic -Wall -Werror -c deck.c
cards.o: cards.c
	gcc -std=gnu99 -g -ggdb3 -pedantic -Wall -Werror -c cards.c

