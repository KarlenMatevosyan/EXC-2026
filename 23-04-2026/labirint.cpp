#include <iostream>

using namespace std;

void print(char arr[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool canMove(char arr[12][12], int i, int j) {
    return (i >= 0 && i < 12 && j >= 0 && j < 12 && arr[i][j] == ' ');
}



void move(char arr[12][12], char &direction, int &i, int &j) {
    int posI = i;
    int posJ = j;

    if (direction == '>') {
        posJ++;
    } else if (direction == '<') {
        posJ--;
    } else if (direction == '^') {
        posI--;
    } else if (direction == 'v') {
        posI++;
    }

    if (canMove(arr, posI, posJ)) {
        arr[i][j] = ' ';
        i = posI;
        j = posJ;
        arr[i][j] = 'o';
    } else {
        if (direction == '>') {
            direction = 'v';
        } else if (direction == 'v') {
            direction = '<';
        } else if (direction == '<') {
            direction = '^';
        } else if (direction == '^') {
            direction = '>';
        }
    }
    print(arr);
}

int main() {
    int i;
    int j;
    char direction = '>';

    i = 2;
    j = 0;

    cout << "\nPress ENTER to see the object's next steps\n";

    char arr[12][12] = {

        '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#',
        'o', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#',
        '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#',
        '#', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', ' ', '#',
        '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',
        '#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',
        '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',
        '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#',
        '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#',
        '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'};

    while (true) {
        cout << "i:" << i << ", j:" << j << ", direction: " << direction << endl;
        cin.ignore(100, '\n');

        move(arr, direction, i, j);
    }

    return 0;
}