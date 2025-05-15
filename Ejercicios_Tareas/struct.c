#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define POKEMONS_NUMBER 150
#define True 1
#define False 0

typedef struct {
  int id;
  char name[20];
  int health;
  int attack;
} Pokemon;

Pokemon pokedex[POKEMONS_NUMBER];

void printMenu() {
  printf("--------------------Pokedex--------------------\n");
  printf("Opciones:\n");
  printf("1 -> Registrar pokemon\n");
  printf("2 -> Consultar pokemon\n");
  printf("3 -> Eliminar pokemon\n");
  printf("4 -> Comparar pokemones\n");
  printf("5 -> Enfrentar pokemones\n");
  printf("6 -> Salir");
}

Pokemon searchPokemonByName(char *pokemonName, Pokemon pokedex[]) {
  for(int i = 0; i < POKEMONS_NUMBER; i++) {
    if(strcmp(pokemonName, pokedex[i].name) == 0){
      return pokedex[i];
    }
  }
  Pokemon notFound = {-1, "Not-Found",-1,-1};
  return notFound;
}

void getPokemonByName(char *pokemonName) {
  Pokemon pokemon = searchPokemonByName("Pikachu", pokedex);
  if(strcmp(pokemon.name, "Not-Found") == 0) {
    printf("Pokemon no encontrado\n");
  }
  else {
    printf("Nombre: %s\n", pokemon.name);
    printf("Id: %d\n", pokemon.id);
    printf("Salud: %d\n", pokemon.health);
    printf("Ataque: %d\n", pokemon.attack);
  }
}

void registerPokemon(int id, char *name, int health, int attack, Pokemon pokedex[]) {
  pokedex[id - 1].id = id;
  strcpy(pokedex[id - 1].name, name);
  pokedex[id - 1].health = health;
  pokedex[id - 1].attack = attack;
}

int main() {

  for(int i = 0; i < POKEMONS_NUMBER; i++) {
    registerPokemon(i + 1, "FREE", 0, 0, pokedex);
  }

  return 0;
}
