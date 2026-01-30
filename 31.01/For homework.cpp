#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct VideoShop {
    string title;
    string director;
    string genre;
    float rating;
    float price;
};

//Add a film
void addFilm(vector<VideoShop>& films) {
    VideoShop f;
    cout << "Film title: ";
    getline(cin, f.title);
    cout << "Director: ";
    getline(cin, f.director);
    cout << "Genre: ";
    getline(cin, f.genre);
    cout << "Popularity rating: ";
    cin >> f.rating;
    cout << "Disk price: ";
    cin >> f.price;
    cin.ignore();

    films.push_back(f);
}

//Show all films
void showAll(const vector<VideoShop>& films) {
    for (const auto& f : films) {
        cout << "\nTitle: " << f.title
            << "\nDirector: " << f.director
            << "\nGenre: " << f.genre
            << "\nRating: " << f.rating
            << "\nPrice: " << f.price << endl;
    }
}

//Search by title
void searchByTitle(const vector<VideoShop>& films, const string& title) {
    for (const auto& f : films) {
        if (f.title == title) {
            cout << "Found film: " << f.title << endl;
        }
    }
}

//Search by genre
void searchByGenre(const vector<VideoShop>& films, const string& genre) {
    for (const auto& f : films) {
        if (f.genre == genre) {
            cout << f.title << endl;
        }
    }
}

//Search by director
void searchByDirector(const vector<VideoShop>& films, const string& director) {
    for (const auto& f : films) {
        if (f.director == director) {
            cout << f.title << endl;
        }
    }
}

//Most popular film in a genre
void mostPopularInGenre(const vector<VideoShop>& films, const string& genre) {
    float maxRating = -1;
    string bestFilm;

    for (const auto& f : films) {
        if (f.genre == genre && f.rating > maxRating) {
            maxRating = f.rating;
            bestFilm = f.title;
        }
    }

    if (maxRating != -1)
        cout << "Most popular film: " << bestFilm << endl;
    else
        cout << "No films found\n";
}

int main() {
    vector<VideoShop> films;
    int choice;
    string input;

    do {
        cout << "\n1. Add film"
            << "\n2. Show all films"
            << "\n3. Search by title"
            << "\n4. Search by genre"
            << "\n5. Search by director"
            << "\n6. Most popular film in genre"
            << "\n0. Exit\n";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addFilm(films);
            break;
        case 2:
            showAll(films);
            break;
        case 3:
            cout << "Enter title: ";
            getline(cin, input);
            searchByTitle(films, input);
            break;
        case 4:
            cout << "Enter genre: ";
            getline(cin, input);
            searchByGenre(films, input);
            break;
        case 5:
            cout << "Enter director: ";
            getline(cin, input);
            searchByDirector(films, input);
            break;
        case 6:
            cout << "Enter genre: ";
            getline(cin, input);
            mostPopularInGenre(films, input);
            break;
        }
    } while (choice != 0);

    return 0;
}
