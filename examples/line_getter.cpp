#include <allegro5/allegro.h>


#include <fstream>
#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> fetch_lines_from_file(std::string filename)
{
   std::vector<std::string> result;

   std::string s;
   std::ifstream in;
   in.open(filename);

   while(!in.eof())
   {
     getline(in, s);
     result.push_back(s);
   }
   in.close();

   return result;
}

int random_int(int min, int max)
{
   return rand()%(max-min+1) + min;
}

template<class T>
T random_element(std::vector<T> &elements)
{
   return elements[random_int(0, elements.size()-1)];
}



void initialize()
{
   al_init();

   ALLEGRO_PATH *resource_path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
   al_change_directory(al_path_cstr(resource_path, ALLEGRO_NATIVE_PATH_SEP));
   al_destroy_path(resource_path);;

   srand(time(NULL));
}


int main(int argc, char **argv)
{
   initialize();

   std::vector<std::string> lines = fetch_lines_from_file("data/file_with_lines.txt");
   std::string random_line = random_element(lines);

   std::cout << "Your random line is: " << random_line << std::endl;
}
