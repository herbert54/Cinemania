#include "FLoader.h"

FLoaderFuncion::FLoaderFuncion() {}
FLoaderUsuario::FLoaderUsuario() {}
FLoaderFuncion::FLoaderFuncion(const string &_path) : FLoader(_path) {}
FLoaderPelicula::FLoaderPelicula() : FLoader("data/pelicula.csv") {}
FLoaderUsuario::FLoaderUsuario(const string &_path) : FLoader(_path) {}
FLoaderPelicula::FLoaderPelicula(const string &_path) : FLoader(_path) {}

void FLoaderUsuario::asignarObjetos(const vector<string> &_lineas)
{
    for (auto st : _lineas)
    {
        stringstream linea(st);
        string componente;
        vector<string> args;
        while (getline(linea, componente, ','))
        {
            args.push_back(componente);
        }
        objetos.push_back(new Usuario(args[0], args[1], args[2], args[3]));
    }
}
void FLoaderPelicula::asignarObjetos(const vector<string> &_lineas)
{
    for (auto st : _lineas)
    {
        stringstream linea(st);
        string componente;
        vector<string> args;
        while (getline(linea, componente, ','))
        {
            args.push_back(componente);
        }
        objetos.push_back(new Pelicula(args[0], args[2], stoi(args[1])));
    }
}
void FLoaderFuncion::asignarObjetos(const vector<string> &_lineas)
{
    for (auto st : _lineas)
    {
        stringstream linea(st);
        string componente;
        vector<string> args;
        while (getline(linea, componente, ','))
        {
            args.push_back(componente);
        }
        objetos.push_back(new Funcion(vector<string>{args[0], args[1], args[2], args[3], args[4]}));
    }
}

vector<string> FLoaderPelicula::juntarPalabras()
{
    vector<string> result;

    for (auto i : objetos)
    {
        string csv_u{i->getNombre() + "," + to_string(i->getTiempo()) + "," + i->getScriptPath()};
        result.push_back(csv_u);
    }

    return result;
}
vector<string> FLoaderUsuario::juntarPalabras()
{
    vector<string> result;

    for (auto i : objetos)
    {
        string csv_u{i->getNombre() + "," + i->getApellido() + "," + i->getDni() + "," + i->getClave()};
        result.push_back(csv_u);
    }

    return result;
}
vector<string> FLoaderFuncion::juntarPalabras()
{
    vector<string> result;

    for (auto i : objetos)
    {
        Funcion j = *i;
        string csv_u{j.getPeli().getNombre() + "," + to_string(j.getNroSala()) +
                     "," + j.getPeli().getScriptPath() + "," + to_string(j.getPeli().getTiempo()) +
                     "," + to_string(j.getSala().getAforo())};
        result.push_back(csv_u);
    }

    return result;
}

FLoaderFuncion::~FLoaderFuncion() {}
FLoaderPelicula::~FLoaderPelicula() {}
FLoaderUsuario::~FLoaderUsuario() {}