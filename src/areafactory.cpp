#include "areafactory.h"


vector<AreaGraphic> AreaFactory::m_vector;



void AreaFactory::load()
{

    cout<<"Areas should be loaded !"<<endl;
}

void AreaFactory::saveArea(Area *area,string fileName)
{
    fstream file(fileName.c_str(),ios::out);

    if(file)
    {
        /// sauvegarde des types
        for(int i=0;i<area->getHeight();i++)
        {
            for(int j=0;j<area->getWidth();j++)
            {
                file<<area->getTile(j,i)->getType()<<" ";
            }file<<endl;
        }
        ///
        ///sauvegarde des objets
        Object *o=0;
        file<<'@'<<" "<<endl; ///marque de fin des tuiles
        for(int i=0;i<area->nbObject();i++)
        {
            o=area->getObject(i);
            /// '@' indique qu'il s'agit d'un objet
            file<<'@'<<" "<<o->getType()<<" "<<o->getX()<<" "<<o->getY()<<" "<<o->getWidth()<<" "<<o->getHeight()<<" "<<o->getSolid()<<" "<<endl;
        }
        file.close();

        cout<<fileName<<" saved !"<<endl;
    }else cerr<<"Cant save "<<fileName<<" in AreaFactory::saveArea !"<<endl;
}

void AreaFactory::loadArea(Area *a,string fileName)
{
    fstream file(fileName.c_str(),ios::in);
    string line;
    int currentLine=0;

    string currentNb("");
    bool tilesOver=false;

    vector<int> *tmp=0;
    vector<vector<int> > content;

    int w=10000;
    int h=0;

    /// pour le chargement de l'objet
    int obj_type=0;
    float obj_x=0.,
          obj_y=0.,
          obj_w=0.,
          obj_h=0.;
    bool obj_obstacle=false;
    ///
    string str_tmp="";///intermédiaire pour la conversion en flottant
    int posInfo=0;///position de l'information sans compter les espaces

    if(file)
    {

        while( getline(file,line) )
        {
            if(!tilesOver)///CHARGEMENT DES TUILES
            {
                if(line[0]!='@')//on vérifie qu'on a pas terminé les tuiles
                {
                    tmp=new vector<int>;


                    for(int j=0;j<(int)(line.size());j++)
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
                    if((int)(tmp->size())<w)w=tmp->size(); //on prend la ligne la plus petite
                    h++;
                    ///

                    content.push_back(*tmp);
                }
                else
                {
                    a->newSize(w,h);
                    a->setTiles(content);
                    delete tmp;

                    tilesOver=true;//on attaque les objets !
                    //!\\ on perd la première ligne (celle inutile ou il n'y a que '@' )
                }
            }
            else ///CHARGEMENT DES OBJETS
            {
                posInfo=0;
                for(int i=0;i<(int)(line.size());i++)
                {
                    if(line[i]!=' ')
                    {
                        str_tmp+=line[i];
                    }
                    else
                    {
                        switch(posInfo)
                        {
                            case 0:break;// '@'
                            case 1: obj_type=Global::strToInt(str_tmp);break;
                            case 2: obj_x=Global::strToFloat(str_tmp);break;
                            case 3: obj_y=Global::strToFloat(str_tmp);break;
                            case 4: obj_w=Global::strToFloat(str_tmp);break;
                            case 5: obj_h=Global::strToFloat(str_tmp);break;
                            case 6: obj_obstacle=Global::strToBool(str_tmp);break;

                        }

                        posInfo++;
                        str_tmp="";
                    }
                }

                a->addObject(new Object(a,obj_type,obj_x,obj_y,obj_w,obj_h,obj_obstacle));//on ajoute l'objet à la zone


            }

            currentLine++;
        }




        file.close();



        cout<<fileName<<" loaded !"<<endl;
    }else cerr<<"Cant load "<<fileName<<" in AreaFactory::loadArea !"<<endl;




}

AreaGraphic AreaFactory::get(int i)
{
    if(i<=0 || i>= (int)(m_vector.size())){cerr<<"ERREUR ACCES AREA FACTORY"<<endl; return AreaGraphic(0,0);}
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
