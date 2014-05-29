#include "../include/tool.h"

Tool::Tool()
{
    //ctor
}



/**
std::pair<float,float> Tool::toIso(float x,float y)
>>>>>>> .r23
{
<<<<<<< .mine
    std::pair<float,float> res;
    float xres=x;
    float yres=y - Global::WINDOW_HEIGHT;
=======
            /**
            on pose l'�criture d'une matrice:
                Matrice[indice] tel que:
                    B0  [0 1 ]
                         2 3
>>>>>>> .r23

<<<<<<< .mine
    res.first=xres;
    res.second=yres;
}
=======
>>>>>>> .r23

<<<<<<< .mine
std::pair<float,float> Tool::toInvOrtho(int x,int y)
{
    std::pair<float,float> res;
    float xres=x;
    float yres=y + Global::WINDOW_HEIGHT;

    res.first=xres;
    res.second=yres;
}

std::pair<float,float> Tool::toIso(float x,float y)
{
    std::pair<float,float> iso;
    float alpha=-3.14/3;
    int i=x;
    int j=y;

    float xRes=i*cos(alpha)  - j*sin(alpha);
    float yRes=i*sin(alpha) +  j*cos(alpha);

=======

    std::pair<float,float> iso;
    std::vector<float> matrix;
    matrix.push_back(0.5        );              //0
    matrix.push_back(sqrt(2)/2 );               //1
    matrix.push_back(1          );              //2
    matrix.push_back(0          );              //3

    float   yRes=matrix[0]*x+matrix[1]*y,
            xRes=matrix[2]*x+matrix[3]*y;
>>>>>>> .r23
    iso.first=xRes;
    iso.second=yRes;
    return iso;
}**/


/** Ce qui suit est un essaie pour le moment infructueux de ToIso() **/


std::pair<float,float> Tool::toIso(float x,float y)
{
            /*
                Matrice[indice] tel que:
                    B0  [0 1 ]
                         2 3
                         */


    std::pair<float,float> iso;
    std::vector<float> matrix;

    float   i=Global::TILE_WIDTH/5,
            j=Global::TILE_HEIGHT/5;

            /*
                Ce que j'ai nomm� i et j est expliqu� dans le "i&j.jpg" que j'ai mis en dropBox
            */



    matrix.push_back(0.5        );              //0
    matrix.push_back(sqrt(2)/2 );               //1
    matrix.push_back(-0.5          );              //2
    matrix.push_back(0          );              //3

    float   xRes=matrix[0]*x+matrix[1]*y,
            yRes=matrix[2]*x+matrix[3]*y;
    iso.first=xRes;
    iso.second=yRes;
    return iso;
}


std::pair<float,float> Tool::toInvIso(float x,float y)
///A mettre � jour
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
    /**Fonctionne parfaitement, ne pas oublier de consid�rer l'origine,
    Genre dans un carr�, il faut dire que l'origine est le coin inf�rieur gauche pour que ca affiche bien, sinon y'a
    un d�calage de TILE_HEIGHT **/

    std::pair<float, float> res;
    res.first=x;
    res.second=Global::WINDOW_HEIGHT-y;

    return res;
}

float   Tool::toOrthoX(float x)
///Existe dans le cas o* le rep�re horizontale orthogonal changerait....
{
    return x;
}

float   Tool::toOrthoY(float y)
/**Permet de ramener une coord Y en bas de l'�cran,
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
/** Ecrit tout le contenu d'un string � la fin d'un txt donn� **/
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
