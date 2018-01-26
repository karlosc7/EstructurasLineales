#include <cstddef> // contiene std::exit()
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
   string name;
   vector<double> grades;
};

int main()
{
   // abrimos el archivo en modo lectura:
   fstream file{"estudiantes.txt",ios::in|ios::binary};
   if (!file) {
      cerr << "Unable to open the file\n";
      exit(EXIT_FAILURE);
   }

   // extraemos los datos del archivo:
   vector<Student> listStudents;
   Student st; // estudiante auxiliar
   size_t size;
   double grade;
   while (getline(file,st.name)) {
      file >> size;
      file.ignore();
      for (size_t i = 0; i < size; ++i) {
         file >> grade;
         file.ignore();
         st.grades.push_back(grade);
      }
      listStudents.push_back(st); // guardamos al estudiante auxiliar en la lista
      st.grades.clear(); // vaciamos el vector del estudiante auxiliar
   }

   // imprimimos los nombres y las notas medias por pantalla:
   for (Student const& s : listStudents) {
      cout << "Name: " << s.name << "\nAverage grade: ";
      double total = 0.0;
      for (double d : s.grades)
         total += d;

      cout << total/3.0
           << "\n------------------" << endl;
   }

   cout << "\nPress ENTER to log out...";
   cin.get();
}
