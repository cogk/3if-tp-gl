CC        = g++
CFLAGS    = -ansi -pedantic -Wall -Wextra -std=c++11
# ajout du flag -Wextra

EXEC_NAME = airwatcher
INCLUDES  =
LIBS      = $(shell find src -type f -name '*.h')
SRCS      = $(shell find src -type f -name '*.cpp')
OBJS      = $(addprefix tmp/,$(SRCS:src/%.cpp=%.o))

ifdef DEBUG
	CFLAGS += -DMAP -g
endif


# On ne compile que les fichiers qui en ont besoin
normal: directories $(EXEC_NAME)

# On recompile tout
all: clean normal

# Cible de test
test: normal
	cd Tests/ && bash ./mktest.sh

# On supprime les fichiers temporaires et l'éxécutable
clean:
	@rm -f $(EXEC_NAME)
	@rm -r tmp/

# Création du répertoire temporaire
directories:
	mkdir -p $(dir $(OBJS))

# Règle de compilation
tmp/%.o: src/%.cpp $(LIBS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< -lm

# Règle d'édition de liens
$(EXEC_NAME): $(OBJS) $(LIBS)
	$(CC) -o $(EXEC_NAME) $(OBJS) -lm

# Permet d'éviter que les fichiers du même nom que des règles
# soient "interprétés" comme des dépendances.
.PHONY: clean all normal test
