#include <iostream>
#include "Exception.h"

using namespace std;

int main() {
    try {
        int capacity = 10;

        Array<int> a(capacity);

        for (int i = 0; i < capacity; i++) {
            a += i;
        }

        for (int i = 0; i < capacity; i++) {
            cout << a[i] << " ";
        }
        cout << endl;

        //****COMENTARII PENTRU A TESTA FIECARE CAZ****//

        // Testare out of range
        // a[11] = 11;

        // Testare inexistent
        /*
        int index = a.Find(11);
        if (index == -1) {
            throw Inexistent();
        }
        else {
            cout << "Elementul se afla pe pozitia " << index << endl;
        }
        */
    }
    catch (IndexOutOfRange& e) {
        cerr << e.what() << endl;
    }
    catch (Inexistent& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
