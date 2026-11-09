#include "cMundo.h"
#pragma warning(disable : 4996)

cMundo::cMundo()
{
	ListaPaises = new cListaT<cPais>();
}

cMundo::~cMundo()
{
	if(ListaPaises!=NULL)
		delete ListaPaises;
}

void cMundo::LeerArchivo(const char* Filename)
{

	FILE* fp = NULL; //file pointer
	fp = fopen(Filename, "r"); //Abrir archivo
	char buffer[200] = "";
	int pos = 0;

	if (fp == NULL)
		throw new std::runtime_error(" --- Error al abrir el archivo ---");

	//leo primera linea (son los paises que tiene el mapa)
	fgets(buffer, 199, fp);
	string Cadena = buffer; //me guardo lo que lei y le saco el \n
	Cadena.resize(Cadena.size()-1, '\n'); //le saco el \n molesto

	string Limitrofes;
	//sigo recorriendo el archivo de texto para los paises limitrofes
	while (!feof(fp))
	{
		fgets(buffer, 199, fp); //leo por linea
		Limitrofes += buffer; //me guardo la linea
	}

	do
	{
		string NombrePais = BuscarNombrePais(Cadena, '-', &pos); //busco el nombre del pais que quiero crear
		PaisesLimitrofes(Limitrofes, NombrePais); //creo la lista de limitrofes + el pais correspondiente
		Cadena.erase(0, (pos + 1)); //borro el nombre que había encontrado

	} while (pos != Cadena.npos);

	fclose(fp); //cierro el archivo
	
	SetNombreMundo(Filename); 

	return;
}

void cMundo::SetNombreMundo(string str) {
	const size_t separator = str.find_last_of("/\\");
	if (separator != string::npos)
		str = str.substr(separator + 1);

	if (str == "argentina.txt")
		this->setNombre("Argentina y sus limitrofes");
	else if (str == "latin-america.txt")
		this->setNombre("America Latina");
	else if (str == "springfield.txt")
		this->setNombre("Springfield");
	return;
}


void cMundo::PaisesLimitrofes(string& Limitrofes, string nombre) {

	int i = 0, pos = 0;

	//primero divido por linea
	vector<string> ListaLimitrofes; //lista con size 0
	pos = Limitrofes.find('\n'); //busco los separadores
	string subCadena = Limitrofes.substr(0, pos); //me copio el elemento 
	Limitrofes = Limitrofes.erase(0, pos + 1); //borro el elemento

	pos = 0;
	//segundo divido por separador
	while (pos != subCadena.npos)
	{
		string NombrePais = BuscarNombrePais(subCadena, '-', &pos);
		ListaLimitrofes.push_back(NombrePais); //agrego pais limitrofe
		subCadena.erase(0, pos + 1); //+1 para que me borre el \n
	}

	*ListaPaises + new cPais(nombre, ListaLimitrofes);
	
	return; 
}

string cMundo::BuscarNombrePais(string str, char separator, int* pos)
{

	*pos = str.find(separator); //busco los separadores
	string word = str.substr(0, *pos); //me guardo el nombre del string

	return word;
}

cListaT<cPais>* cMundo::GetLista()
{
	return ListaPaises;
}

void cMundo::setNombre(string nombre)
{
	this->Nombre = nombre;
}


string MAPA(const char* filename) {

	FILE* fp = fopen(filename, "r");
	string cadena;
	char buffer[200] = "";

	if (fp != NULL) {
		while (!feof(fp))
		{
			fgets(buffer, 199, fp); //leo por linea
			cadena += buffer;
		}
		return cadena;
	}
	else
		throw new std::runtime_error(" --- Error al abrir el archivo ---");
}


void cMundo::Imprimir() const
{
	
	if (Nombre == "America Latina") {
		system("color 0C");
		cout << MAPA("assets/ascii/latin-america.txt");
		Sleep(1000);
	}

	if (Nombre == "Argentina y sus limitrofes") {
		system("color 0C");
		PlaySound(TEXT("assets/audio/argentina-theme.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Sleep(1000);
		cout << MAPA("assets/ascii/argentina.txt");
		Sleep(6000);
	}

	if (Nombre == "Springfield") {
		system("color 06");
		PlaySound(TEXT("assets/audio/springfield-theme.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Sleep(1000);
		cout << MAPA("assets/ascii/springfield.txt");
		Sleep(4000);
	}

	system("cls");
	system("color 07");

	return;

}






void cMundo::SetUp(const char* Filename)
{
	try
	{
		LeerArchivo(Filename);
	}
	catch (std::runtime_error* ex)
	{
		string error = ex->what();
		delete ex;
		ex = new std::runtime_error((error + " :: No hay mundo para setear").c_str());
		throw ex;

	}
}
