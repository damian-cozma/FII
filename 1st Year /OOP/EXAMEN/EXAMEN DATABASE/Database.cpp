#include "Database.h"

Database &Database::operator+=(Entry *obj) {
    entries.push_back(obj);
    return *this;
}

vector<Entry *>::iterator Database::begin() {
    return entries.begin();
}

vector<Entry *>::iterator Database::end() {
    return entries.end();
}

void Database::Print() {
    for (auto i: entries)
    {
        i->Print();
    }
    printf("\n");
}

Database &Database::operator-=(string remove) {
    for (auto i=entries.begin(); i!=entries.end();)
    {
        if ((*i)->GetName() == remove)
        {
            entries.erase(i);
            break;
        }
        ++i;
    }
    return *this;
}
