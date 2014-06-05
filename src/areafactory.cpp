#include "areafactory.h"


vector<AreaGraphic> AreaFactory::m_vector;



void AreaFactory::load()
{

    cout<<"Areas loaded !"<<endl;
}

void AreaFactory::saveArea(Area *area,string fileName)
{
    fstream file(fileName.c_str(),ios::out);

    if(file)
    {
        for(int i=0;i<area->getHeight();i++)
        {
            for(int j=0;j<area->getWidth();j++)
            {
                file<<area->getTile(j,i)->getType()<<" ";
            }file<<endl;
        }

        file.close();

        cout<<fileName<<" saved !"<<endl;
    }else cerr<<"Cant save "<<fileName<<" in AreaFactory::saveArea !"<<endl;
}

void AreaFactory::loadArea(Area *a,string fileName)
{
    fstream file(fileName.c_str(),ios::in);
    string line;
    string currentNb("");

    vector<int> *tmp=0;
    vector<vector<int> > content;

    int w=10000,w_tmp=0;
    int h=0,h_tmp=0;

    if(file)
    {
        while( getline(file,line) )
        {
            tmp=new vector<int>;


            for(int j=0;j<line.size();j++)
            {
                if(line[j]==' ')
                {
                    tmp->push_back( Global::strToInt(currentNb) );
                    currentNb="";
                }
                else
                {
                    currentNb+=line[j];

                }
            }
            ///détermination de la hauteur et largeur de l'area
            if(tmp->size()<w)w=tmp->size(); //on prend la ligne la plus petite
            h++;
            ///

            content.push_back(*tmp);

        }

        delete tmp;
        file.close();



        cout<<fileName<<" loaded !"<<endl;
    }else cerr<<"Cant load "<<fileName<<" in AreaFactory::loadArea !"<<endl;


    a->newSize(w,h);
    a->setTiles(content);

}

AreaGraphic AreaFactory::get(int i)
{
    if(i<=0 || i>= m_vector.size())cerr<<"ERREUR ACCES AREA FACTORY"<<endl;
    else
    {
        return m_vector[i];
    }
}
























AreaFactory::AreaFactory()
{
    //ctor
}

AreaFactory::~AreaFactory()
{
    //dtor
}
