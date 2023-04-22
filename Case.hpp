#include "GameElement.hpp"

using namespace std;

class Case
{

public:
    Case(){
        vector<GameElement> liste = new vector<GameElement>;
    };
    ~Case(){
        delete[] liste;
    };
    void displayCase();
    void addElem(GameElement elem){
        liste..push_back(elem);
    }

    void addElem(GameElement elem){
        liste..push_back(elem);
    }

protected:
    vector<GameElement> liste;

};

