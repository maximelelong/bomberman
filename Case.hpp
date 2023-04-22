#include "GameElement.hpp"

using namespace std;

class Case : public Displayable
{

public:
    Case(){  // on met des pointeurs pour permettre le polymorphisme
        list<GameElement*> liste = new list<GameElement*>();
    };
    ~Case(){
        delete[] liste;
    };
    void displayCase();

    void addElem(GameElement* elem){
        liste.push_back(elem);
    }

    void suppElem(GameElement* elem);

protected:
    vector<GameElement*> liste;

};

