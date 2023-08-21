all: main.o labirinto.o percurso.o posicao.o arvore.o allegro.o
	@gcc main.o labirinto.o percurso.o posicao.o arvore.o allegro.o -o exe -lallegro -lallegro_font -lallegro_image
	@rm *.o
main.o: main.c
	@gcc main.c -c -Wall
labirinto.o: labirinto.c
	@gcc labirinto.c -c -Wall
percurso.o: percurso.c
	@gcc percurso.c -c -Wall
posicao.o: posicao.c
	@gcc posicao.c -c -Wall
arvore.o: arvore.c
	@gcc arvore.c -c -Wall
allegro.o: allegro.c
	@gcc allegro.c -c -Wall
run:
	@./exe
