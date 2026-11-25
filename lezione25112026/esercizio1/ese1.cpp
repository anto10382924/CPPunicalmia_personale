#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Webpage
{
    private:
        const string title;
        const string text;
        vector <const Webpage*> links;
    public:
        Webpage()=delete;   //non diamo la possibilità di creare webpage senza titolo e testo
        Webpage(string t, string tx, vector <const Webpage*> l):title(t),text(tx),links(l){}
        ~Webpage(){
            for (int i=0;i < links.size();++i)
                delete links[i];
        }
        string getTitle() const{return title;}
        string getText() const{return text;}
        const vector <const Webpage*> getLinks(){return links;}
        void addLink(const Webpage* nuova){links.push_back(nuova);}
        bool operator==(const Webpage& other) const
        {
            return other.title == this -> title;
        }
        bool operator!=(const Webpage& other) const
        {
            return other.title != this -> title;
        }
};

class Website
{

};