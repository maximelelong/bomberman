#include "Case.hpp"

using namespace std

class Terrain : public D {

    public:
        void displayBackground();
        void displayToutesLesCases(){
            for (size_t i = 0; i < listeCases.size(); i++){
                listeCases[i].displayCase();
            }
        }

    protected:

    vector<case> listeCases;
}