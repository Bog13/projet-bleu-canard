#include "../include/tool.h"

Tool::Tool()
{
    //ctor
}

std::pair<float,float> Tool::toIso(float x,float y)
{
            /**
            on pose l'écriture d'une matrice:
                Matrice[indice] tel que:
                    B0  [0 1 ]
                         2 3
            **/


    std::pair<float,float> iso;
    std::vector<float> matrix;
    matrix.push_back(0.5        );              //0
    matrix.push_back(sqrt(2)/2 );               //1
    matrix.push_back(1          );              //2
    matrix.push_back(0          );              //3

    float   yRes=matrix[0]*x+matrix[1]*y,
            xRes=matrix[2]*x+matrix[3]*y;
    iso.first=xRes;
    iso.second=yRes;
    return iso;
}


/** Ce qui suit est un essaie pour le moment infructueux de ToIso()


std::pair<float,float> Tool::toIso(float x,float y)
{
            /*
                Matrice[indice] tel que:
                    B0  [0 1 ]
                         2 3


    std::pair<float,float> iso;
    std::vector<float> matrix;

    float   i=Global::TILE_WIDTH/5,
            j=Global::TILE_HEIGHT/5;

            /*
                Ce que j'ai nommé i et j est expliqué dans le "i&j.jpg" que j'ai mis en dropBox



    matrix.push_back( 1         );              //0     /// Ici il nous faut une matrice qui marche.
    matrix.push_back( 1-i         );               //1
    matrix.push_back(  0         );              //2
    matrix.push_back( 1-j          );              //3

    float   yRes=matrix[0]*x+matrix[1]*y,
            xRes=matrix[2]*x+matrix[3]*y;
    iso.first=xRes;
    iso.second=yRes;
    return iso;
}
**/

std::pair<float,float> Tool::toInvIso(float x,float y)
///A mettre à jour
{
    float xOrtho=toOrtho(x,y).first;
    float yOrtho=toOrtho(x,y).second;
    std::pair<float,float> iso;
    float demiSqrDeux= sqrt(2)/2;

    float xRes= demiSqrDeux*x-y;
    float yRes= demiSqrDeux*x+y;

    iso.first=xRes;
    iso.second=yRes;
    return iso;
}

std::pair<float,float>   Tool::toOrtho(float x,float y)
{
    /**Fonctionne parfaitement, ne pas oublier de considérer l'origine,
    Genre dans un carré, il faut dire que l'origine est le coin inférieur gauche pour que ca affiche bien, sinon y'a
    un décalage de TILE_HEIGHT **/

    std::pair<float, float> res;
    res.first=x;
    res.second=Global::WINDOW_HEIGHT-y;

    return res;
}

float   Tool::toOrthoX(float x)
///Existe dans le cas o* le repère horizontale orthogonal changerait....
{
    return x;
}

float   Tool::toOrthoY(float y)
/**Permet de ramener une coord Y en bas de l'écran,
je pense que ca devrait servir seulement aux dessins,
 pas aux calculs **/
{
    return (Global::WINDOW_HEIGHT-y);
}

static std::string Load(std::string name)
/** Ouvre un fstream sur le name.txt et renvoie un string contenant tout le txt **/
{
    std::fstream reader(name.c_str());
    if(!reader) {std::cout<<" There was a problem loading the " << name << " from the Tool::Load member function. " << std::endl;}
    if(reader)
    {
        std::string line, finalResult;
        while(std::getline(reader,line))    {finalResult+=line;}

        return finalResult;


    }

}

const void Tool::Save(std::string name,std::string text)
/** Ecrit tout le contenu d'un string à la fin d'un txt donné **/
{
    std::fstream writter(name.c_str(),std::ios::out);
    if(!writter) {std::cout<<"There was a problem writting the " << name << " file." << std::endl;}
    if(writter) {writter<<text;}
    writter.close();
}



Tool::~Tool()
{
    //dtor
}
