#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_SIZE 100
#define GENRE_SIZE 100
#define FILENAME "movies.txt"

typedef struct {
    char title[TITLE_SIZE];
    char genre[GENRE_SIZE];
    int year;
    float rating;
    int flag;
} Movie;

typedef Movie *MovieList;

MovieList initMovieList(int size) {
    MovieList movies = (MovieList)malloc(size * sizeof(Movie));
    for (int i = 0; i < size; i++) {
        movies[i].flag = 0;
    }
    return movies;
}

void loadMoviesFromFile(char *filename, MovieList movies) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s for reading\n", filename);
        return;
    }
    int i = 0;
    while (i < MAX_MOVIES && fscanf(fp, "%99[^\n]\n%99[^\n]\n%d\n%f\n", movies[i].title, movies[i].genre, &movies[i].year, &movies[i].rating) == 4) {
        movies[i].flag = 1;
        i++;
    }
    fclose(fp);
}

void saveMoviesToFile(MovieList movies, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s for writing\n", filename);
        return;
    }
    for (int i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].flag == 1) {
            fprintf(fp, "%s\n%s\n%d\n%f\n", movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
        }
    }
    fclose(fp);
}

void viewMovies(MovieList movies) {
    int empty = 1;
    for (int i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].flag == 1) {
            printf("Title: %s\nGenre: %s\nYear: %d\nRating: %.2f\n\n", movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
            empty = 0;
        }
    }
    if (empty) {
        printf("Empty list!\n");
    }
}

void insertMovie(MovieList movies, Movie *newMovie) {
    for (int i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].flag == 0) {
            strcpy(movies[i].title, newMovie->title);
            strcpy(movies[i].genre, newMovie->genre);
            movies[i].year = newMovie->year;
            movies[i].rating = newMovie->rating;
            movies[i].flag = 1;
            break;
        }
    }
}

Movie* searchMovie(MovieList movies, char *title) {
    for (int i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].flag && strcmp(movies[i].title, title) == 0) {
            return &movies[i];
        }
    }
    return NULL;
}

int main() {
    int input;
    MovieList movies = initMovieList(MAX_MOVIES);
    Movie newMovie;

    loadMoviesFromFile(FILENAME, movies);

    do {
        printf("\nEnter a number between 1 and 4\n");
        printf("1 - Display Movies\n");
        printf("2 - Add a Movie\n");
        printf("3 - Search for a Movie\n");
        printf("4 - Exit\n");

        scanf("%d", &input);

        switch (input) {
            case 1:
                viewMovies(movies);
                break;
            case 2:
                printf("Enter title: ");
                scanf("\n%99[^\n]", newMovie.title);
                printf("Enter genre: ");
                scanf("\n%99[^\n]", newMovie.genre);
                printf("Enter year: ");
                scanf("%d", &newMovie.year);
                printf("Enter rating: ");
                scanf("%f", &newMovie.rating);
                insertMovie(movies, &newMovie);
                break;
            case 3:
                printf("Enter the title to search for: ");
                scanf("\n%99[^\n]", newMovie.title);
                Movie *foundMovie = searchMovie(movies, newMovie.title);
                if (foundMovie != NULL) {
                    printf("Title: %s\nGenre: %s\nYear: %d\nRating: %.2f\n", foundMovie->title, foundMovie->genre, foundMovie->year, foundMovie->rating);
                } else {
                    printf("Movie not found!\n");
                }
                break;
            default:
                input = 0;
                break;
        }
    } while (input != 0);

    saveMoviesToFile(movies, FILENAME);
    free(movies);

    return EXIT_SUCCESS;
}
