
nomeAula=Mensagem

all: $(nomeAula)

$(nomeAula): mensagem.o funcoes.o
	gcc -o $(nomeAula) mensagem.o funcoes.o


mensagem.o: mensagem.c
	gcc -c mensagem.c 

funcoes.o: funcoes.c
	gcc -c funcoes.c 
clean:
	rm -f *.o *.gch $(nomeAula)
