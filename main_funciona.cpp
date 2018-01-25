#include <iostream>
#include "pel_array.hpp" // Header included
#include <string>

using namespace std;

class DVD { //DVD object
      std::string titulo_;
      double precio_;
public:
      DVD() { }
      string& titulo(){return titulo_;}
      double& precio(){return precio_;}

};
int main()
{
    pel::Array<DVD,3> m; // Take matrice DVD x3
    for(int i=0; i < m.size(); ++i){
        cout << "Titulo: ";
        getline(cin, m[i].titulo());
        cout << "Precio: ";
        cin >> m[i].precio();
        cin.ignore();

    }
    for(int i=0;i < m.size();++i){ //Print titles and price
        cout << m[i].titulo() << '\n' << m[i].precio() << endl;
        }

}
