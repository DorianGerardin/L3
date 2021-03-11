########################################
#~ définitions
########################################

# nom de l'executable
#BIN=runPeriod

BIN=bin/client  bin/serveur  bin/client2  bin/serveur2  bin/client3  bin/serveur3  bin/client4  bin/serveur4
#BIN=bin/serveur

# liste des fichiers sources 
SRCS0=client.c
SRCS1=serveur.c
SRCS3=client2.c
SRCS4=serveur2.c
SRCS5=client3.c
SRCS6=serveur3.c
SRCS7=client4.c
SRCS8=serveur4.c

default: $(BIN)

########################################
#~ regles pour l'executable
########################################

obj/%.o: %.c
	gcc -Wall -Iinclude -c $< -o $@

bin/client: $(SRCS0:%.c=obj/%.o)
	gcc -lpthread -o $@ $+

bin/serveur: $(SRCS1:%.c=obj/%.o)
	gcc -lpthread -o $@ $+

bin/client2: $(SRCS3:%.c=obj/%.o)
	gcc -lpthread -o $@ $+

bin/serveur2: $(SRCS4:%.c=obj/%.o)
	gcc -lpthread -o $@ $+

bin/client3: $(SRCS5:%.c=obj/%.o)
	gcc -lpthread -o $@ $+

bin/serveur3: $(SRCS6:%.c=obj/%.o)
	gcc -lpthread -o $@ $+

bin/client4: $(SRCS7:%.c=obj/%.o)
	gcc -lpthread -o $@ $+

bin/serveur4: $(SRCS8:%.c=obj/%.o)
	gcc -lpthread -o $@ $+

clean:
	rm -f $(BIN) obj/*.o *~
