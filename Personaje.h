#include <bits/stdc++.h>
using namespace std;

class Personaje
{

    private:
        int vida;
        string nombre;
        int defensa;
        int pA;
        int curacion;
        int ataque;
        int BP=0;
    public:
        Personaje();
        Personaje(string , int , int , int, int, int);
        friend ostream& operator<<(ostream &out, Personaje &m){
            out<<"Nombre: "<<m.Getnombre()<<endl;
            out<<"Vida: "<<m.Getvida()<<endl;
            out<<"Defensa: "<<m.Getdefensa()<<endl;
            out<<"puntos de accion: "<<m.GetpA()<<endl;
        }

        int Getvida(){return vida;}
        void Setvida(int val) { vida = val; }
        string Getnombre() { return nombre; }
        void Setnombre(string val) { nombre = val; }
        int Getdefensa() { return defensa; }
        void Setdefensa(int val) { defensa = val; }
        int GetpA() { return pA; }
        void SetpA(int val) { pA = val; }
        int Getcuracion() { return curacion; }
        void Setcuracion(int val) { curacion = val; }
        int Getataque() { return ataque; }
        void Setataque(int val) { ataque = val; }
        void atacado(int );
        void SetBP(){BP=2;}
        void SeBP(){BP--;}
        int GetBP(){return BP;}
};

Personaje::Personaje(){};

Personaje::Personaje(string _nombre, int _vida, int _Ataque, int _curacion, int _defensa, int _pA)
{
        nombre = _nombre;
        vida = _vida;
        ataque = _Ataque;
        curacion = _curacion;
        defensa = _defensa;
        pA = _pA;
}

class mago : public Personaje
{
     private:
        string debuff;
        string buff;
        string estado = "Defensa";
        string atqE = "debil";
        int PA = 2;
        int PS = 3;
        int PE =3;

    public:

        mago();


        string Getdebuff() { return debuff; }
        void Setdebuff(string val) { debuff = val; }
        string Getbuff() { return buff; }
        void Setbuff(string val) { buff = val; }
        string Getestado() { return estado; }
        void Setestado(string val) { estado = val; }
         string GetatqE(){ return atqE;}
        int GetPA(){return PA;}
        int GetPS(){return PS;}
        int GetPe(){return PE;}

       friend ostream& operator<<(ostream &out, mago &m){
            out<<"Nombre: "<<m.Getnombre()<<endl;
            out<<"Vida: "<<m.Getvida()<<endl;
            out<<"Defensa: "<<m.Getdefensa()<<endl;
            out<<"puntos de accion: "<<m.GetpA()<<endl;
            out<<"1 - 2PA "<<"ataque: "<<m.Getataque()<<endl;
            out<<"2 - 3PA "<<"Curacion: "<<m.Getcuracion()<<endl;
            out<<"3 - 3PA brillo magico: "<<m.GetatqE()<<endl;
            out<<"4 - 1PA Barrera magica: Defensa"<<endl;
           out<<"Debuff: "<<m.debuff<<endl;
           out<<"Buff: "<<m.buff<<endl;
       }


};

mago::mago() : Personaje("mago juan", 100, 50, 20, 35, 14)
{
}

class guerrero : public Personaje
{
     private:
        string debuff;
        string buff;
        string estado = "Fuerza";
        string atqE = "debil";
        int PA = 2;
        int PS = 3;
        int PE =3;

    public:
        guerrero();

        string Getdebuff() { return debuff; }
        void Setdebuff(string val) { debuff = val; }
        string Getbuff() { return buff; }
        void Setbuff(string val) { buff = val; }
        string Getestado() { return estado; }
        void Setestado(string val) { estado = val; }
         string GetatqE(){ return atqE;}
        int GetPA(){return PA;}
        int GetPS(){return PS;}
        int GetPe(){return PE;}
        

    protected:



         friend ostream& operator<<(ostream &out, guerrero &m){
            out<<"Nombre: "<<m.Getnombre()<<endl;
            out<<"Vida: "<<m.Getvida()<<endl;
            out<<"Defensa: "<<m.Getdefensa()<<endl;
            out<<"puntos de accion: "<<m.GetpA()<<endl;
            out<<"1 - 2PA "<<"ataque: "<<m.Getataque()<<endl;
            out<<"2 - 3PA "<<"Curacion: "<<m.Getcuracion()<<endl;
            out<<"3 - 3PA Espada cortante: "<<m.GetatqE()<<endl;
            out<<"4 - 1PA Espada santa: Fuerza"<<endl;
           out<<"Debuff: "<<m.debuff<<endl;
           out<<"Buff: "<<m.buff<<endl;
       }
};
guerrero::guerrero() : Personaje("Guerrero pedro",120,70,10,20,18)
{
}

class Arquero : public Personaje
{
     private:
        string debuff;
        string buff;
        string estado = "Defensa";
        string atqE = "vulnerable";
        int PA = 2;
        int PS = 3;
        int PE = 3;

    public:
        Arquero();

        string Getdebuff() { return debuff; }
        void Setdebuff(string val) { debuff = val; }
        string Getbuff() { return buff; }
        void Setbuff(string val) { buff = val; }
        string Getestado() { return estado; }
        void Setestado(string val) { estado = val; }
        string GetatqE(){ return atqE;}
        int GetPA(){return PA;}
        int GetPS(){return PS;}
        int GetPe(){return PE;}

    protected:



          friend ostream& operator<<(ostream &out, Arquero &m){
            out<<"Nombre: "<<m.Getnombre()<<endl;
            out<<"Vida: "<<m.Getvida()<<endl;
            out<<"Defensa: "<<m.Getdefensa()<<endl;
            out<<"puntos de accion: "<<m.GetpA()<<endl;
            out<<"1 - 2PA "<<"ataque: "<<m.Getataque()<<endl;
            out<<"2 - 3PA "<<"Curacion: "<<m.Getcuracion()<<endl;
            out<<"3 - 3PA flecha belica: "<<m.GetatqE()<<endl;
            out<<"4 - 1PA escudo de flechas: Defensa"<<endl;
           out<<"Debuff: "<<m.debuff<<endl;
           out<<"Buff: "<<m.buff<<endl;
       }
};
Arquero::Arquero() : Personaje("Arquero Rose",80,80,5,20,20)
{
}








