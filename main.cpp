/*
*Proyecto Final POO
*Rodrigo Muñoz Guerrero
*A00572858
*11/06/2020
*
*Este es el proyecto final de la clase TC1030 Programación Orientada a Objetos.
*Es un programa que captura diferentes cervezas dependiendo su tipo de
*fermentación. Se tiene una lista de deseos y un catálogo de cervezas
*ya probadas donde se les puede dar una puntuación segun el gusto.
*De la lista de deseos se puede agregar una cerveza, quitar una cerveza de la
*lista o ver la lista. De la lista de cervezas ya probadas se puede agregar o
*ver las cervezas junto con su evaluación propia.
*/

#include <iostream> //Para imprimir

using namespace std;

//Declaración de clase User
class User{

    //Declaro variables privadas de instancia
    private:
        string name;
        string password;

    //Declaro el constructor
    public:
        User(string nam, string pass);
};

//Declaro las variables de instancia del constructor
User::User(string nam, string pass){
    name = nam;
    password = pass;
}

//Declaro clase padre abstracta Beer
class Beer{

    //DEclaro varibales de instancia que heredarán las clases hijas
    protected:
        string bname;
        string brewery;
        int ratebeer;

    //Declaro los constructores y métodos que tendrá la clase padre
    public:
        Beer(string b_name, string brewery_);
        Beer(string b_name, string brewery_,int ratebe);
        virtual void imprimir()=0; //método escrito que será sobreescrito
        int getrate(){ //Declaro método para usar getters
            return ratebeer;
        };
};

//Declaro el constructor que se usará para la lista de deseos ya que ésta no tiene una evaluación propia
Beer::Beer(string b_name, string brewery_){
    bname = b_name;
    brewery = brewery_;
}


//Declaro el constructor que se usará para la lista de mis cervezas
Beer::Beer(string b_name, string brewery_, int ratebe){
bname = b_name;
brewery = brewery_;
ratebeer = ratebe;
}

//Declaro primera clase hija Top (Del tipo de fermentación)
class Top : public Beer {

    //Declaro variables privadas de instancia
    private:
        string bstyle;
        int bitterness;
        float abv;

    //Declaro constructores y métodos de la clase hija
    public:
        void imprimir(); //Imprime todos los atributos que se le dan al objeto
        Top(); //Constructor por default
        Top(string bname, string brewery, string bs, int bitt, float abvv):Beer(bname, brewery){
        bstyle = bs;
        bitterness = bitt;
        abv = abvv;
        }
        Top(string bname, string brewery, string bs, int bitt, float abvv,int ratebeer):Beer(bname, brewery, ratebeer){
        bstyle = bs;
        bitterness = bitt;
        abv = abvv;
        }
};

/*
*imprimir() imprime todos los atributos que se le dieron al objeto
*/

//imprime uno por uno las características que se le dieron a la cerveza
void Top::imprimir(){
cout << "Fermentation: Top" << endl;
cout << "Beer name: " << bname << endl;
cout << "Beer brewery: " << brewery << endl;
cout << "Beer style: " << bstyle << endl;
cout << "Beer IBUs: " << bitterness << endl;
cout << "Beer Alcohol percentage: " << abv << endl;
cout << "\n" << endl;
}

//Declaro la segunda clase hija de tipo de fermentación Bottom
class Bottom : public Beer {

    //Declaro las variables privadas de instancia
    private:
        string bstyle;
        int bitterness;
        float abv;

    //Declaro los constructores y métodos de la clase hija
    public:
        void imprimir(); //Imprime todos los atributos que se le dan al objeto
        Bottom(); //Constructor por default
        Bottom(string bname, string brewery, string bs, int bitt, float abvv):Beer(bname, brewery){
        bstyle = bs;
        bitterness = bitt;
        abvv = abv;
        }
        Bottom(string bname, string brewery, string bs, int bitt, float abvv,int ratebeer):Beer(bname, brewery, ratebeer){
        bstyle = bs;
        bitterness = bitt;
        abv = abvv;
        }
};

//imprime uno por uno las características que se le dieron a la cerveza
void Bottom::imprimir(){
cout << "Fermentation: Bottom" << endl;
cout << "Beer name: " << bname << endl;
cout << "Beer brewery: " << brewery << endl;
cout << "Beer style: " << bstyle << endl;
cout << "Beer IBUs: " << bitterness << endl;
cout << "Beer Alcohol percentage: " << abv << endl;
cout << "\n" << endl;
}

//Declaro la tercera clase hija de tipo de fermentación Spontaneous
class Spontaneous : public Beer {

    //Declaro las variables privadas de instancia
    private:
        string bstyle;
        int bitterness;
        float abv;

    //Declaro los constructores y métodos de la clase hija
    public:
        void imprimir(); //Imprime todos los atributos que se le dan al objeto
        Spontaneous(); //Constructor por default
        Spontaneous(string bname, string brewery, string bs, int bitt, float abvv):Beer(bname, brewery){
        bstyle = bs;
        bitterness = bitt;
        abvv = abv;
        }
        Spontaneous(string bname, string brewery, string bs, int bitt, float abvv,int ratebeer):Beer(bname, brewery, ratebeer){
        bstyle = bs;
        bitterness = bitt;
        abv = abvv;
        }
};

//imprime uno por uno las características que se le dieron a la cerveza
void Spontaneous::imprimir(){
cout << "Fermentation: Spontaneous" << endl;
cout << "Beer name: " << bname << endl;
cout << "Beer brewery: " << brewery << endl;
cout << "Beer style: " << bstyle << endl;
cout << "Beer IBUs: " << bitterness << endl;
cout << "Beer Alcohol percentage: " << abv << endl;
cout << "\n" << endl;
}

//Declaro la clase de la lista de deseos
class Wishlist{

//Declaro las variables privadas de instancia
private:
    Beer* Beers[100]; //Defino una lista de tipo Clase padre Beer de 100 cervezas
    int numWbeers = 0; //Defino e inicializo una variable que me servirá como contador de las cervezas en la lista

//DEclaro el constructor por default y los métodos de la clase
public:
    void showwishlist();
    void addwishlist(string typee, string b_name, string brewery_, string bs, int bitt, float abvv);
    void delete_W();
    void drankit();
    Wishlist(){}; //Constructor por default
};

/*
*addwishlist genera objetos de las tres clases hijas y las mete a la lista Beers[]
*
*genera objetos de las tres clases hijas, las mete en el arreglo de Beers[] y aumenta la variable contador
*
*@param string typee debe ser: 'Top', 'Bottom' o 'Spontaneous', string b_name es el nombre de la cerveza
*string brewery_ es el nombre de la cervecería, string bs es el estilo de la cerveza, int bitt es
*la cantidad de IBUs de la cerveza (medida de amargor), float abvv es el porcentaje de alcohol de la cerveza.
*@return
*/
void Wishlist::addwishlist(string typee, string b_name, string brewery_, string bs, int bitt, float abvv){
    if (typee == "Top" || typee == "top"){
        Beers[numWbeers] = new Top(b_name,brewery_,bs,bitt,abvv);
        numWbeers++;
    }
    else if (typee == "Bottom" || typee == "bottom"){
        Beers[numWbeers] = new Bottom(b_name,brewery_,bs,bitt,abvv);
        numWbeers++;
    }
    else if (typee == "Spontaneous" || typee == "spontaneous"){
        Beers[numWbeers] = new Spontaneous(b_name,brewery_,bs,bitt,abvv);
        numWbeers++;
    }
}

/*
*showwishlist imprime todos los objetos dentro de la lista Beers[]
*
*Si el número de cervezas en el arreglo Beers[] es diferente de cero, mandará llamar la función imprimir
*de las clases hijas y mostrará todos los atributos del objeto, si no, mostrará un mensaje diciendo que
*no hay cervezas en la lista
*
*@param
*@return
*/
void Wishlist::showwishlist(){
    if (numWbeers==0){
        cout << "You have not a beer on your wishlist, drink more!!" << endl;
    }
    else{
        for (int i=0;i<numWbeers;i++){
            cout << i+1 << endl;
            Beers[i]->imprimir();
        }
    }
}

/*
*delete_W borra todas las cervezas de la lista de deseos
*
*Recorre todo el arreglo de Beers[] y borra uno por uno los objetos en ella
*
*@param
*@return
*/
void Wishlist::delete_W(){
    for (int i=0;i<numWbeers;i++){
        delete Beers[i];
    }
}

/*
*drankit quita cierta cerveza de la lista de deseos
*
*Se ingresa el numero asignado a la cerveza que se desea eliminar de la lista de deseos
*y recorre el resto de la lista un espacio hacia atras para dejar la cerveza seleccionada
*fuera de la lista
*
*@param
*@return
*/
void Wishlist::drankit(){
    cout << "Which is the number of the beer you want to take out of the wishlist?" << endl;
    int beernum;
    cin >> beernum;
    for (int i = beernum-1;i<numWbeers;i++)
    {
        Beers[i] = Beers[i+1];
        numWbeers = numWbeers - 1;
    };
}

//Declaro la clase de "mi lista de cervezas" o catalogo propio
class MyBeers{

//Declaro las variables privadas de instancia
private:
    Beer* MBeers[100]; //Defino un arreglo de tipo Clase padre Beer de 100 espacios
    int numMbeers = 0; //Defino e inicializo una variable que me servirá como contador de las cervezas en la lista

//Declaro los métodos y constructor de la clase
public:
    void showmybeers();
    float meanrate();
    void addmybeers(string typee, string b_name, string brewery_, string bs, int bitt, float abvv, int rate);
    void delete_MB();
    MyBeers(){}; // Constructor por default
};

/*
*addmybeers genera objetos de las tres clases hijas y las mete al arreglo MBeers[]
*
*genera objetos de las tres clases hijas, las mete en el arreglo de MBeers[] y aumenta la variable contador
*
*@param string typee debe ser: 'Top', 'Bottom' o 'Spontaneous', string b_name es el nombre de la cerveza
*string brewery_ es el nombre de la cervecería, string bs es el estilo de la cerveza, int bitt es
*la cantidad de IBUs de la cerveza (medida de amargor), float abvv es el porcentaje de alcohol de la cerveza,
*int rate es la evalución propia de la cerveza que se está introduciendo a la lista.
*@return
*/
void MyBeers::addmybeers(string typee, string b_name, string brewery_, string bs, int bitt, float abvv, int rate){
    if (typee == "Top" || typee == "top"){
        MBeers[numMbeers] = new Top(b_name,brewery_,bs,bitt,abvv,rate);
        numMbeers++;
    }
    else if (typee == "Bottom" || typee == "bottom"){
        MBeers[numMbeers] = new Bottom(b_name,brewery_,bs,bitt,abvv,rate);
        numMbeers++;
    }
    else if (typee == "Spontaneous" || typee == "spontaneous"){
        MBeers[numMbeers] = new Spontaneous(b_name,brewery_,bs,bitt,abvv,rate);
        numMbeers++;
    }
}

/*
*showmybeers imprime todos los objetos dentro de la lista MBeers[]
*
*Si el número de cervezas en el arreglo MBeers[] es diferente de cero, mandará llamar la función imprimir
*de las clases hijas y mostrará todos los atributos del objeto, si no, mostrará un mensaje diciendo que
*no hay cervezas en la lista
*
*@param
*@return
*/
void MyBeers::showmybeers(){
    if (numMbeers==0){
        cout << "You have not a beer on your catalog, drink more!!" << endl;
    }
    else{
        for (int i=0;i<numMbeers;i++){
            cout << i+1 << endl;
            MBeers[i]->imprimir();
            cout << "Your rate for this beer = " << MBeers[i]->getrate() <<"\n" << endl;
        }
    }
}

/*
*delete_MB borra todas las cervezas de la lista de "Mis cervezas"
*
*Recorre todo el arreglo de MBeers[] y borra uno por uno los objetos en ella
*
*@param
*@return
*/
void MyBeers::delete_MB(){
    for (int i=0;i<numMbeers;i++){
        delete MBeers[i];
    }
}

/*
*meanrate calcula el promedio de las evaluaciones propias
*
*Inicializa la variable de "mean" (donde se hará la suma de todas las evaluaciones) y
*"d" (sirve como contador de cuantos datos se han sumado para poder calcular el promedio),
*Se irá una por una cerveza de la lista de MBeers y con un getter obtendrá el valor de
*la evaluación y sumandola a la variable "mean" al igual que con cada iteración se
*suma una unidad a la varibale contador "d". Después, se calcula el promedio.
*
*@param
*@return float del promedio calculado dividiendo la variable "mean" entre la variable "d"
*/
float MyBeers::meanrate(){
    int mean = 0;
    int d = 0;
    for (int i = 0;i<numMbeers;i++){
        Beer *temporal = MBeers[i];
        mean  = mean + temporal->getrate();
        d++;
    }
    float answer = mean/d;
    return answer;
}

string username; //Defino la varibale de nombre de usuario
string passw; //Defino la variable de contraseña del usuario
string ans; //Defino la variable temporal de la respuesta de una decisión en el main
int age1; //Defino la variable de edad del usuario
string wans; //Defino la variable temporal de la respuesta de una decisión en el main
string bans; //Defino la variable temporal de la respuesta de una decisión en el main
string beername; //Defino la variable de nombre de la cerveza
string beerbrewery; //Defino la variable de nombre de la cervecería de la cerveza
string beerstyle; //Defino la variable del estilo de la cerveza
string type; //Defino la variable temporal de tipo de fermentación de la cerveza
int beeribu; //Defino la variable de numero de IBUs de la cerveza
float beerabv; //Defino la variable de porcentaje de alcohol de la cerveza
int rate; //Defino la variable de evaluación propia de la cerveza
int beernum; //Defino la variable que servirá para saber que cerveza sacar de la lista de deseos
string finalans; //Defino la variable temporal de la decision de hacer otra acción con la cuenta
int i; //Defino la variable de contador para ciclos for

int main()
{
    MyBeers* mybeeers = new MyBeers(); //Creo objeto de clase de lista de deseos
    Wishlist* wishie = new Wishlist(); //Creo objeto de clase de lista de "Mis cervezas"
    cout << "Create an account to log in" << endl;
    cout << "Name:" << endl;
    cin >> username;
    cout << "Password:" << endl;
    cin >> passw;
    cout << "Age:" << endl;
    cin >> age1;

    if (age1>=18)
        {
        User* Userone = new User(username,passw); //Creo objeto de clase User
        }
    else
        {
        cout << "You are not overage";
        return -1;
        }

    while (true)
        {
        cout << "\nYou want to use your _wishlist_ or your catalog _mybeers_?" << endl;
        cin >> ans;
        if (ans == "wishlist" || ans == "Wishlist")
            {
            cout << "\nYou want to _see_ your wish list, _add_ a beer or take a beer _out_ your wishlist?" << endl;
            cin >> wans;
            if (wans == "add" || wans == "ADD" || wans == "Add")
                {
                cout << "Fermentation type (Top, Bottom or Spontaneous)" << endl;
                type = "";
                cin >> type;
                cout << "Beer name:" << endl;
                beername = "";
                cin >> beername;
                cout << "Brewery:" << endl;
                beerbrewery = "";
                cin >> beerbrewery;
                cout << "Beer style:" << endl;
                beerstyle = "";
                cin >> beerstyle;
                cout << "IBUs:" << endl;
                beeribu = 0;
                cin >> beeribu;
                cout << "Beer ABV:" << endl;
                beerabv = 0.0;
                cin >> beerabv;
                wishie->addwishlist(type,beername,beerbrewery,beerstyle,beeribu,beerabv);
                }
            else if (wans == "out" || wans == "Out" || wans == "OUT")
                {
                wishie->showwishlist();
                wishie->drankit();
                }
            else if (wans == "see" || wans == "See" || wans == "SEE")
                {
                wishie->showwishlist();
                }
            else{
                cout << "ERROR" << endl;
                break;
                }
            }
        else if (ans == "mybeers" || ans == "MyBeers" || ans == "Mybeers")
        {
            cout << "\nYou want to _see_ your beers or _add_ a beer you have tried?" << endl;
            cin >> bans;
            if (bans == "see" || bans == "See" || bans == "SEE")
            {
                mybeeers->showmybeers();
                cout << "\nThe mean of the rates of your beers is = " << mybeeers->meanrate() << endl;
            }
            else if (bans == "add" || bans == "Add" || bans == "ADD")
            {
                cout << "Fermentation type (Top, Bottom or Spontaneous)" << endl;
                type = "";
                cin >> type;
                cout << "Beer name:" << endl;
                beername = "";
                cin >> beername;
                cout << "Brewery:" << endl;
                beerbrewery = "";
                cin >> beerbrewery;
                cout << "Beer style:" << endl;
                beerstyle = "";
                cin >> beerstyle;
                cout << "IBUs:" << endl;
                beeribu = 0;
                cin >> beeribu;
                cout << "Beer ABV:" << endl;
                beerabv = 0.0;
                cin >> beerabv;
                cout << "What rate from 1 to 5 (being 5 completely spectacular) do you give the beer?" << endl;
                rate  = 0;
                cin >> rate;
                mybeeers->addmybeers(type,beername,beerbrewery,beerstyle,beeribu,beerabv,rate);
            };
        }
        else{
            cout << "INVALID" << endl;
            continue;
            };
        cout << "\nDo you want to do another action with your profile?\nYES    NO" << endl;
        finalans = "";
        cin >> finalans;
        if (finalans == "yes" || finalans == "YES" || finalans == "Yes")
            {
            continue;
            }
        else if (finalans == "no" || finalans == "NO" || finalans == "No")
            {
            break;
            }
        else {
            cout << "ERROR" << endl;
            break;
            }
    }
    wishie->delete_W();
    mybeeers->delete_MB();
    delete wishie;
    delete mybeeers;
}
