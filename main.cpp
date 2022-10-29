#include <bits/stdc++.h>
#include "Personaje.h"
#include "peleas.h"
typedef long long LL;
#define pb push_back
#define ciclo(i,x) for(int i=0;i<x;i++)
#define cicloR(i,x) for(int i=x-1;i>=0;i--)
#define TestCase(x) for(int Te=1;Te<=x;Te++)

using namespace std;

int jug1;
int jug2;

void clearConsole(){
    system("pause");
    system("cls");
}

void arch(int gan)
{
    FILE *arch;
    arch=fopen("Resultados.dat","wb");
    if(arch==NULL) exit(1);
    fwrite(&gan, sizeof(int), 1, arch);
}


int main()
{
    int a=0;
    while(a==0)
    {
        int gana;
        cout<<"Hola bienvenido..... elije un jugador\n";
        cout<<"Jugador 1 elige..\n";
        cout<<"1- Mago Juan\n";
        cout<<"2- Guerrero Pedro\n";
        cout<<"-3 Arquero Rosa\n";

        cin>>jug1;

        cout<<"Jugador 2 elige..\n";
        cout<<"1- Mago Juan\n";
        cout<<"2- Guerrero Pedro\n";
        cout<<"-3 Arquero Rosa\n";

        cin>>jug2;

        clearConsole();
        
        if(jug1==1)
        {
            mago p1;
            if(jug2==1)
            {
                mago p2;
                while(p1.Getvida()> 0 && p2.Getvida()>0)
                {
                    int sel1,sel2;
                    p1.SeBP();
                    if(p1.Getbuff()!="" && p1.GetBP()<=0 )
                    {
                        p1.Setbuff("");
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()-5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()-5);}
                    }
                    p2.SeBP();
                    if(p2.Getbuff()!="" && p2.GetBP()<=0 )
                    {
                        p2.Setbuff("");
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()-5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()-5);}
                    }
                    pelea3();
                    cout<<"jugador uno elja que hacer.....\n";
                    cout<<p1;
                    cin>>sel1;
                    if(sel1==1 && (p1.GetpA()-p1.GetPA())>=0)
                    {
                        int ataque;
                        if(p1.Getdebuff()=="debil")
                        {
                            ataque = (p1.Getataque()/4)*3;
                            p1.Setdebuff("");
                        }
                        else{
                            ataque = p1.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex = ataque/2;
                            int res=p2.Getvida()+p2.Getdefensa()-ataque-ex;
                            p2.Setvida(res);
                            p2.Setdebuff("");
                        }
                        else
                        {
                            int res=p2.Getvida()+p2.Getdefensa()-p1.Getataque();
                            p2.Setvida(res);
                        }
                        p1.SetpA(p1.GetpA()-p1.GetPA());
                    }
                    else if(sel1==2 && (p1.GetpA()-p1.GetPS())>=0)
                    {
                        int res = p1.Getcuracion()+p1.Getvida();
                        p1.SetpA(p1.GetpA()-p1.GetPS());
                    }
                    else if(sel1==3 && (p1.GetpA()-p1.GetPe())>=0)
                    {
                        p2.Setdebuff(p1.GetatqE());
                        p1.SetpA(p1.GetpA()-p1.GetPe());
                    }
                    else if(sel1==4 && (p1.GetpA()-1)>=0)
                    {
                        p1.Setbuff(p1.Getestado());
                        p1.SetpA(p1.GetpA()-1);
                        p1.SetBP();
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()+5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p2.Getvida()<0){gana=1;break;}
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                    pelea3();
                    cout<<"jugador dos elja que hacer.....\n";
                    cout<<p2;
                    cin>>sel2;
                    if(sel2==1 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int ataque;
                        if(p2.Getdebuff()=="debil")
                        {
                            ataque = (p2.Getataque()/4)*3;
                            p2.Setdebuff("");
                        }
                        else{
                            ataque = p2.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex =  ataque/2;
                            int res=p1.Getvida()+p1.Getdefensa()-ataque-ex;
                            p1.Setvida(res);
                            p1.Setdebuff("");
                        }
                        else
                        {
                            int res=p1.Getvida()+p1.Getdefensa()-ataque;
                            p1.Setvida(res);
                        }
                        p2.SetpA(p2.GetpA()-p2.GetPA());
                    }
                    else if(sel2==2 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int res = p2.Getcuracion()+p2.Getvida();
                        p2.SetpA(p2.GetpA()-p2.GetPS());
                    }
                    else if(sel2==3 &&  (p2.GetpA()-p2.GetPe())>=0)
                    {
                        p1.Setdebuff(p2.GetatqE());
                        p2.SetpA(p2.GetpA()-p2.GetPe());
                    }
                    else if(sel2==4 && (p2.GetpA()-1)>=0)
                    {
                        p2.Setbuff(p2.Getestado());
                        p2.SetpA(p2.GetpA()-1);
                        p2.SetBP();
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()+5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                }
                if(p1.Getvida()<=0){gana=2;}
            }
            if(jug2==2)
            {
                guerrero p2;
                while(p1.Getvida()> 0 && p2.Getvida()>0)
                {
                    int sel1,sel2;
                    p1.SeBP();
                    if(p1.Getbuff()!="" && p1.GetBP()<=0 )
                    {
                        p1.Setbuff("");
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()-5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()-5);}
                    }
                    p2.SeBP();
                    if(p2.Getbuff()!="" && p2.GetBP()<=0 )
                    {
                        p2.Setbuff("");
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()-5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()-5);}
                    }
                    pelea2();
                    cout<<"jugador uno elja que hacer.....\n";
                    cout<<p1;
                    cin>>sel1;
                    if(sel1==1 && (p1.GetpA()-p1.GetPA())>=0)
                    {
                        int ataque;
                        if(p1.Getdebuff()=="debil")
                        {
                            ataque = (p1.Getataque()/4)*3;
                            p1.Setdebuff("");
                        }
                        else{
                            ataque = p1.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex = ataque/2;
                            int res=p2.Getvida()+p2.Getdefensa()-ataque-ex;
                            p2.Setvida(res);
                            p2.Setdebuff("");
                        }
                        else
                        {
                            int res=p2.Getvida()+p2.Getdefensa()-p1.Getataque();
                            p2.Setvida(res);
                        }
                        p1.SetpA(p1.GetpA()-p1.GetPA());
                    }
                    else if(sel1==2 && (p1.GetpA()-p1.GetPS())>=0)
                    {
                        int res = p1.Getcuracion()+p1.Getvida();
                        p1.SetpA(p1.GetpA()-p1.GetPS());
                    }
                    else if(sel1==3 && (p1.GetpA()-p1.GetPe())>=0)
                    {
                        p2.Setdebuff(p1.GetatqE());
                        p1.SetpA(p1.GetpA()-p1.GetPe());
                    }
                    else if(sel1==4 && (p1.GetpA()-1)>=0)
                    {
                        p1.Setbuff(p1.Getestado());
                        p1.SetpA(p1.GetpA()-1);
                        p1.SetBP();
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()+5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p2.Getvida()<0){gana=1;break;}
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                    pelea8();
                    cout<<"jugador dos elja que hacer.....\n";
                    cout<<p2;
                    cin>>sel2;
                    if(sel2==1 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int ataque;
                        if(p2.Getdebuff()=="debil")
                        {
                            ataque = (p2.Getataque()/4)*3;
                            p2.Setdebuff("");
                        }
                        else{
                            ataque = p2.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex =  ataque/2;
                            int res=p1.Getvida()+p1.Getdefensa()-ataque-ex;
                            p1.Setvida(res);
                            p1.Setdebuff("");
                        }
                        else
                        {
                            int res=p1.Getvida()+p1.Getdefensa()-ataque;
                            p1.Setvida(res);
                        }
                        p2.SetpA(p2.GetpA()-p2.GetPA());
                    }
                    else if(sel2==2 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int res = p2.Getcuracion()+p2.Getvida();
                        p2.SetpA(p2.GetpA()-p2.GetPS());
                    }
                    else if(sel2==3 &&  (p2.GetpA()-p2.GetPe())>=0)
                    {
                        p1.Setdebuff(p2.GetatqE());
                        p2.SetpA(p2.GetpA()-p2.GetPe());
                    }
                    else if(sel2==4 && (p2.GetpA()-1)>=0)
                    {
                        p2.Setbuff(p2.Getestado());
                        p2.SetpA(p2.GetpA()-1);
                        p2.SetBP();
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()+5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                }
                if(p1.Getvida()<=0){gana=2;}
            }
            if(jug2==3)
            {
                Arquero p2;
                while(p1.Getvida()> 0 && p2.Getvida()>0)
                {
                    int sel1,sel2;
                    p1.SeBP();
                    if(p1.Getbuff()!="" && p1.GetBP()<=0 )
                    {
                        p1.Setbuff("");
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()-5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()-5);}
                    }
                    p2.SeBP();
                    if(p2.Getbuff()!="" && p2.GetBP()<=0 )
                    {
                        p2.Setbuff("");
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()-5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()-5);}
                    }
                    pelea1();
                    cout<<"jugador uno elja que hacer.....\n";
                    cout<<p1;
                    cin>>sel1;
                    if(sel1==1 && (p1.GetpA()-p1.GetPA())>=0)
                    {
                        int ataque;
                        if(p1.Getdebuff()=="debil")
                        {
                            ataque = (p1.Getataque()/4)*3;
                            p1.Setdebuff("");
                        }
                        else{
                            ataque = p1.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex = ataque/2;
                            int res=p2.Getvida()+p2.Getdefensa()-ataque-ex;
                            p2.Setvida(res);
                            p2.Setdebuff("");
                        }
                        else
                        {
                            int res=p2.Getvida()+p2.Getdefensa()-p1.Getataque();
                            p2.Setvida(res);
                        }
                        p1.SetpA(p1.GetpA()-p1.GetPA());
                    }
                    else if(sel1==2 && (p1.GetpA()-p1.GetPS())>=0)
                    {
                        int res = p1.Getcuracion()+p1.Getvida();
                        p1.SetpA(p1.GetpA()-p1.GetPS());
                    }
                    else if(sel1==3 && (p1.GetpA()-p1.GetPe())>=0)
                    {
                        p2.Setdebuff(p1.GetatqE());
                        p1.SetpA(p1.GetpA()-p1.GetPe());
                    }
                    else if(sel1==4 && (p1.GetpA()-1)>=0)
                    {
                        p1.Setbuff(p1.Getestado());
                        p1.SetpA(p1.GetpA()-1);
                        p1.SetBP();
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()+5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p2.Getvida()<0){gana=1;break;}
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                    pelea5();
                    cout<<"jugador dos elja que hacer.....\n";
                    cout<<p2;
                    cin>>sel2;
                    if(sel2==1 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int ataque;
                        if(p2.Getdebuff()=="debil")
                        {
                            ataque = (p2.Getataque()/4)*3;
                            p2.Setdebuff("");
                        }
                        else{
                            ataque = p2.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex =  ataque/2;
                            int res=p1.Getvida()+p1.Getdefensa()-ataque-ex;
                            p1.Setvida(res);
                            p1.Setdebuff("");
                        }
                        else
                        {
                            int res=p1.Getvida()+p1.Getdefensa()-ataque;
                            p1.Setvida(res);
                        }
                        p2.SetpA(p2.GetpA()-p2.GetPA());
                    }
                    else if(sel2==2 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int res = p2.Getcuracion()+p2.Getvida();
                        p2.SetpA(p2.GetpA()-p2.GetPS());
                    }
                    else if(sel2==3 &&  (p2.GetpA()-p2.GetPe())>=0)
                    {
                        p1.Setdebuff(p2.GetatqE());
                        p2.SetpA(p2.GetpA()-p2.GetPe());
                    }
                    else if(sel2==4 && (p2.GetpA()-1)>=0)
                    {
                        p2.Setbuff(p2.Getestado());
                        p2.SetpA(p2.GetpA()-1);
                        p2.SetBP();
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()+5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                }
                if(p1.Getvida()<=0){gana=2;}
            }

        }
        else if(jug1==2)
        {
            guerrero p1;
             if(jug2==1)
            {
                mago p2;
                while(p1.Getvida()> 0 && p2.Getvida()>0)
                {
                    int sel1,sel2;
                    p1.SeBP();
                    if(p1.Getbuff()!="" && p1.GetBP()<=0 )
                    {
                        p1.Setbuff("");
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()-5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()-5);}
                    }
                    p2.SeBP();
                    if(p2.Getbuff()!="" && p2.GetBP()<=0 )
                    {
                        p2.Setbuff("");
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()-5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()-5);}
                    }
                    pelea8();
                    cout<<"jugador uno elja que hacer.....\n";
                    cout<<p1;
                    cin>>sel1;
                    if(sel1==1 && (p1.GetpA()-p1.GetPA())>=0)
                    {
                        int ataque;
                        if(p1.Getdebuff()=="debil")
                        {
                            ataque = (p1.Getataque()/4)*3;
                            p1.Setdebuff("");
                        }
                        else{
                            ataque = p1.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex = ataque/2;
                            int res=p2.Getvida()+p2.Getdefensa()-ataque-ex;
                            p2.Setvida(res);
                            p2.Setdebuff("");
                        }
                        else
                        {
                            int res=p2.Getvida()+p2.Getdefensa()-p1.Getataque();
                            p2.Setvida(res);
                        }
                        p1.SetpA(p1.GetpA()-p1.GetPA());
                    }
                    else if(sel1==2 && (p1.GetpA()-p1.GetPS())>=0)
                    {
                        int res = p1.Getcuracion()+p1.Getvida();
                        p1.SetpA(p1.GetpA()-p1.GetPS());
                    }
                    else if(sel1==3 && (p1.GetpA()-p1.GetPe())>=0)
                    {
                        p2.Setdebuff(p1.GetatqE());
                        p1.SetpA(p1.GetpA()-p1.GetPe());
                    }
                    else if(sel1==4 && (p1.GetpA()-1)>=0)
                    {
                        p1.Setbuff(p1.Getestado());
                        p1.SetpA(p1.GetpA()-1);
                        p1.SetBP();
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()+5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p2.Getvida()<0){gana=1;break;}
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                    pelea2();
                    cout<<"jugador dos elja que hacer.....\n";
                    cout<<p2;
                    cin>>sel2;
                    if(sel2==1 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int ataque;
                        if(p2.Getdebuff()=="debil")
                        {
                            ataque = (p2.Getataque()/4)*3;
                            p2.Setdebuff("");
                        }
                        else{
                            ataque = p2.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex =  ataque/2;
                            int res=p1.Getvida()+p1.Getdefensa()-ataque-ex;
                            p1.Setvida(res);
                            p1.Setdebuff("");
                        }
                        else
                        {
                            int res=p1.Getvida()+p1.Getdefensa()-ataque;
                            p1.Setvida(res);
                        }
                        p2.SetpA(p2.GetpA()-p2.GetPA());
                    }
                    else if(sel2==2 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int res = p2.Getcuracion()+p2.Getvida();
                        p2.SetpA(p2.GetpA()-p2.GetPS());
                    }
                    else if(sel2==3 &&  (p2.GetpA()-p2.GetPe())>=0)
                    {
                        p1.Setdebuff(p2.GetatqE());
                        p2.SetpA(p2.GetpA()-p2.GetPe());
                    }
                    else if(sel2==4 && (p2.GetpA()-1)>=0)
                    {
                        p2.Setbuff(p2.Getestado());
                        p2.SetpA(p2.GetpA()-1);
                        p2.SetBP();
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()+5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                }
                if(p1.Getvida()<=0){gana=2;}
            }
            if(jug2==2)
            {
                guerrero p2;
                while(p1.Getvida()> 0 && p2.Getvida()>0)
                {
                    int sel1,sel2;
                    p1.SeBP();
                    if(p1.Getbuff()!="" && p1.GetBP()<=0 )
                    {
                        p1.Setbuff("");
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()-5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()-5);}
                    }
                    p2.SeBP();
                    if(p2.Getbuff()!="" && p2.GetBP()<=0 )
                    {
                        p2.Setbuff("");
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()-5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()-5);}
                    }
                    pelea9();
                    cout<<"jugador uno elja que hacer.....\n";
                    cout<<p1;
                    cin>>sel1;
                    if(sel1==1 && (p1.GetpA()-p1.GetPA())>=0)
                    {
                        int ataque;
                        if(p1.Getdebuff()=="debil")
                        {
                            ataque = (p1.Getataque()/4)*3;
                            p1.Setdebuff("");
                        }
                        else{
                            ataque = p1.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex = ataque/2;
                            int res=p2.Getvida()+p2.Getdefensa()-ataque-ex;
                            p2.Setvida(res);
                            p2.Setdebuff("");
                        }
                        else
                        {
                            int res=p2.Getvida()+p2.Getdefensa()-p1.Getataque();
                            p2.Setvida(res);
                        }
                        p1.SetpA(p1.GetpA()-p1.GetPA());
                    }
                    else if(sel1==2 && (p1.GetpA()-p1.GetPS())>=0)
                    {
                        int res = p1.Getcuracion()+p1.Getvida();
                        p1.SetpA(p1.GetpA()-p1.GetPS());
                    }
                    else if(sel1==3 && (p1.GetpA()-p1.GetPe())>=0)
                    {
                        p2.Setdebuff(p1.GetatqE());
                        p1.SetpA(p1.GetpA()-p1.GetPe());
                    }
                    else if(sel1==4 && (p1.GetpA()-1)>=0)
                    {
                        p1.Setbuff(p1.Getestado());
                        p1.SetpA(p1.GetpA()-1);
                        p1.SetBP();
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()+5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p2.Getvida()<0){gana=1;break;}
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                    pelea9();
                    cout<<"jugador dos elja que hacer.....\n";
                    cout<<p2;
                    cin>>sel2;
                    if(sel2==1 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int ataque;
                        if(p2.Getdebuff()=="debil")
                        {
                            ataque = (p2.Getataque()/4)*3;
                            p2.Setdebuff("");
                        }
                        else{
                            ataque = p2.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex =  ataque/2;
                            int res=p1.Getvida()+p1.Getdefensa()-ataque-ex;
                            p1.Setvida(res);
                            p1.Setdebuff("");
                        }
                        else
                        {
                            int res=p1.Getvida()+p1.Getdefensa()-ataque;
                            p1.Setvida(res);
                        }
                        p2.SetpA(p2.GetpA()-p2.GetPA());
                    }
                    else if(sel2==2 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int res = p2.Getcuracion()+p2.Getvida();
                        p2.SetpA(p2.GetpA()-p2.GetPS());
                    }
                    else if(sel2==3 &&  (p2.GetpA()-p2.GetPe())>=0)
                    {
                        p1.Setdebuff(p2.GetatqE());
                        p2.SetpA(p2.GetpA()-p2.GetPe());
                    }
                    else if(sel2==4 && (p2.GetpA()-1)>=0)
                    {
                        p2.Setbuff(p2.Getestado());
                        p2.SetpA(p2.GetpA()-1);
                        p2.SetBP();
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()+5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                }
                if(p1.Getvida()<=0){gana=2;}
            }
            if(jug2==3)
            {
                Arquero p2;
                while(p1.Getvida()> 0 && p2.Getvida()>0)
                {
                    int sel1,sel2;
                    p1.SeBP();
                    if(p1.Getbuff()!="" && p1.GetBP()<=0 )
                    {
                        p1.Setbuff("");
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()-5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()-5);}
                    }
                    p2.SeBP();
                    if(p2.Getbuff()!="" && p2.GetBP()<=0 )
                    {
                        p2.Setbuff("");
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()-5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()-5);}
                    }
                    pelea7();
                    cout<<"jugador uno elja que hacer.....\n";
                    cout<<p1;
                    cin>>sel1;
                    if(sel1==1 && (p1.GetpA()-p1.GetPA())>=0)
                    {
                        int ataque;
                        if(p1.Getdebuff()=="debil")
                        {
                            ataque = (p1.Getataque()/4)*3;
                            p1.Setdebuff("");
                        }
                        else{
                            ataque = p1.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex = ataque/2;
                            int res=p2.Getvida()+p2.Getdefensa()-ataque-ex;
                            p2.Setvida(res);
                            p2.Setdebuff("");
                        }
                        else
                        {
                            int res=p2.Getvida()+p2.Getdefensa()-p1.Getataque();
                            p2.Setvida(res);
                        }
                        p1.SetpA(p1.GetpA()-p1.GetPA());
                    }
                    else if(sel1==2 && (p1.GetpA()-p1.GetPS())>=0)
                    {
                        int res = p1.Getcuracion()+p1.Getvida();
                        p1.SetpA(p1.GetpA()-p1.GetPS());
                    }
                    else if(sel1==3 && (p1.GetpA()-p1.GetPe())>=0)
                    {
                        p2.Setdebuff(p1.GetatqE());
                        p1.SetpA(p1.GetpA()-p1.GetPe());
                    }
                    else if(sel1==4 && (p1.GetpA()-1)>=0)
                    {
                        p1.Setbuff(p1.Getestado());
                        p1.SetpA(p1.GetpA()-1);
                        p1.SetBP();
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()+5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p2.Getvida()<0){gana=1;break;}
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                    pelea4();
                    cout<<"jugador dos elja que hacer.....\n";
                    cout<<p2;
                    cin>>sel2;
                    if(sel2==1 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int ataque;
                        if(p2.Getdebuff()=="debil")
                        {
                            ataque = (p2.Getataque()/4)*3;
                            p2.Setdebuff("");
                        }
                        else{
                            ataque = p2.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex =  ataque/2;
                            int res=p1.Getvida()+p1.Getdefensa()-ataque-ex;
                            p1.Setvida(res);
                            p1.Setdebuff("");
                        }
                        else
                        {
                            int res=p1.Getvida()+p1.Getdefensa()-ataque;
                            p1.Setvida(res);
                        }
                        p2.SetpA(p2.GetpA()-p2.GetPA());
                    }
                    else if(sel2==2 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int res = p2.Getcuracion()+p2.Getvida();
                        p2.SetpA(p2.GetpA()-p2.GetPS());
                    }
                    else if(sel2==3 &&  (p2.GetpA()-p2.GetPe())>=0)
                    {
                        p1.Setdebuff(p2.GetatqE());
                        p2.SetpA(p2.GetpA()-p2.GetPe());
                    }
                    else if(sel2==4 && (p2.GetpA()-1)>=0)
                    {
                        p2.Setbuff(p2.Getestado());
                        p2.SetpA(p2.GetpA()-1);
                        p2.SetBP();
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()+5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                }
                if(p1.Getvida()<=0){gana=2;}
            }

        }
        else if(jug1==3)
        {
            Arquero p1;
            if(jug2==1)
            {
                mago p2;
                while(p1.Getvida()> 0 && p2.Getvida()>0)
                {
                    int sel1,sel2;
                    p1.SeBP();
                    if(p1.Getbuff()!="" && p1.GetBP()<=0 )
                    {
                        p1.Setbuff("");
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()-5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()-5);}
                    }
                    p2.SeBP();
                    if(p2.Getbuff()!="" && p2.GetBP()<=0 )
                    {
                        p2.Setbuff("");
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()-5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()-5);}
                    }
                    pelea5();
                    cout<<"jugador uno elja que hacer.....\n";
                    cout<<p1;
                    cin>>sel1;
                    if(sel1==1 && (p1.GetpA()-p1.GetPA())>=0)
                    {
                        int ataque;
                        if(p1.Getdebuff()=="debil")
                        {
                            ataque = (p1.Getataque()/4)*3;
                            p1.Setdebuff("");
                        }
                        else{
                            ataque = p1.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex = ataque/2;
                            int res=p2.Getvida()+p2.Getdefensa()-ataque-ex;
                            p2.Setvida(res);
                            p2.Setdebuff("");
                        }
                        else
                        {
                            int res=p2.Getvida()+p2.Getdefensa()-p1.Getataque();
                            p2.Setvida(res);
                        }
                        p1.SetpA(p1.GetpA()-p1.GetPA());
                    }
                    else if(sel1==2 && (p1.GetpA()-p1.GetPS())>=0)
                    {
                        int res = p1.Getcuracion()+p1.Getvida();
                        p1.SetpA(p1.GetpA()-p1.GetPS());
                    }
                    else if(sel1==3 && (p1.GetpA()-p1.GetPe())>=0)
                    {
                        p2.Setdebuff(p1.GetatqE());
                        p1.SetpA(p1.GetpA()-p1.GetPe());
                    }
                    else if(sel1==4 && (p1.GetpA()-1)>=0)
                    {
                        p1.Setbuff(p1.Getestado());
                        p1.SetpA(p1.GetpA()-1);
                        p1.SetBP();
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()+5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p2.Getvida()<0){gana=1;break;}
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                    pelea1();
                    cout<<"jugador dos elja que hacer.....\n";
                    cout<<p2;
                    cin>>sel2;
                    if(sel2==1 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int ataque;
                        if(p2.Getdebuff()=="debil")
                        {
                            ataque = (p2.Getataque()/4)*3;
                            p2.Setdebuff("");
                        }
                        else{
                            ataque = p2.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex =  ataque/2;
                            int res=p1.Getvida()+p1.Getdefensa()-ataque-ex;
                            p1.Setvida(res);
                            p1.Setdebuff("");
                        }
                        else
                        {
                            int res=p1.Getvida()+p1.Getdefensa()-ataque;
                            p1.Setvida(res);
                        }
                        p2.SetpA(p2.GetpA()-p2.GetPA());
                    }
                    else if(sel2==2 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int res = p2.Getcuracion()+p2.Getvida();
                        p2.SetpA(p2.GetpA()-p2.GetPS());
                    }
                    else if(sel2==3 &&  (p2.GetpA()-p2.GetPe())>=0)
                    {
                        p1.Setdebuff(p2.GetatqE());
                        p2.SetpA(p2.GetpA()-p2.GetPe());
                    }
                    else if(sel2==4 && (p2.GetpA()-1)>=0)
                    {
                        p2.Setbuff(p2.Getestado());
                        p2.SetpA(p2.GetpA()-1);
                        p2.SetBP();
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()+5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                }
                if(p1.Getvida()<=0){gana=2;}
            }
            if(jug2==2)
            {
                guerrero p2;
                while(p1.Getvida()> 0 && p2.Getvida()>0)
                {
                    int sel1,sel2;
                    p1.SeBP();
                    if(p1.Getbuff()!="" && p1.GetBP()<=0 )
                    {
                        p1.Setbuff("");
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()-5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()-5);}
                    }
                    p2.SeBP();
                    if(p2.Getbuff()!="" && p2.GetBP()<=0 )
                    {
                        p2.Setbuff("");
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()-5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()-5);}
                    }
                    pelea4();
                    cout<<"jugador uno elja que hacer.....\n";
                    cout<<p1;
                    cin>>sel1;
                    if(sel1==1 && (p1.GetpA()-p1.GetPA())>=0)
                    {
                        int ataque;
                        if(p1.Getdebuff()=="debil")
                        {
                            ataque = (p1.Getataque()/4)*3;
                            p1.Setdebuff("");
                        }
                        else{
                            ataque = p1.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex = ataque/2;
                            int res=p2.Getvida()+p2.Getdefensa()-ataque-ex;
                            p2.Setvida(res);
                            p2.Setdebuff("");
                        }
                        else
                        {
                            int res=p2.Getvida()+p2.Getdefensa()-p1.Getataque();
                            p2.Setvida(res);
                        }
                        p1.SetpA(p1.GetpA()-p1.GetPA());
                    }
                    else if(sel1==2 && (p1.GetpA()-p1.GetPS())>=0)
                    {
                        int res = p1.Getcuracion()+p1.Getvida();
                        p1.SetpA(p1.GetpA()-p1.GetPS());
                    }
                    else if(sel1==3 && (p1.GetpA()-p1.GetPe())>=0)
                    {
                        p2.Setdebuff(p1.GetatqE());
                        p1.SetpA(p1.GetpA()-p1.GetPe());
                    }
                    else if(sel1==4 && (p1.GetpA()-1)>=0)
                    {
                        p1.Setbuff(p1.Getestado());
                        p1.SetpA(p1.GetpA()-1);
                        p1.SetBP();
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()+5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p2.Getvida()<0){gana=1;break;}
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                    pelea7();
                    cout<<"jugador dos elja que hacer.....\n";
                    cout<<p2;
                    cin>>sel2;
                    if(sel2==1 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int ataque;
                        if(p2.Getdebuff()=="debil")
                        {
                            ataque = (p2.Getataque()/4)*3;
                            p2.Setdebuff("");
                        }
                        else{
                            ataque = p2.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex =  ataque/2;
                            int res=p1.Getvida()+p1.Getdefensa()-ataque-ex;
                            p1.Setvida(res);
                            p1.Setdebuff("");
                        }
                        else
                        {
                            int res=p1.Getvida()+p1.Getdefensa()-ataque;
                            p1.Setvida(res);
                        }
                        p2.SetpA(p2.GetpA()-p2.GetPA());
                    }
                    else if(sel2==2 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int res = p2.Getcuracion()+p2.Getvida();
                        p2.SetpA(p2.GetpA()-p2.GetPS());
                    }
                    else if(sel2==3 &&  (p2.GetpA()-p2.GetPe())>=0)
                    {
                        p1.Setdebuff(p2.GetatqE());
                        p2.SetpA(p2.GetpA()-p2.GetPe());
                    }
                    else if(sel2==4 && (p2.GetpA()-1)>=0)
                    {
                        p2.Setbuff(p2.Getestado());
                        p2.SetpA(p2.GetpA()-1);
                        p2.SetBP();
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()+5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                }
                if(p1.Getvida()<=0){gana=2;}
            }
            if(jug2==3)
            {
                Arquero p2;
                while(p1.Getvida()> 0 && p2.Getvida()>0)
                {
                    int sel1,sel2;
                    p1.SeBP();
                    if(p1.Getbuff()!="" && p1.GetBP()<=0 )
                    {
                        p1.Setbuff("");
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()-5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()-5);}
                    }
                    p2.SeBP();
                    if(p2.Getbuff()!="" && p2.GetBP()<=0 )
                    {
                        p2.Setbuff("");
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()-5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()-5);}
                    }
                    pelea6();
                    cout<<"jugador uno elja que hacer.....\n";
                    cout<<p1;
                    cin>>sel1;
                    if(sel1==1 && (p1.GetpA()-p1.GetPA())>=0)
                    {
                        int ataque;
                        if(p1.Getdebuff()=="debil")
                        {
                            ataque = (p1.Getataque()/4)*3;
                            p1.Setdebuff("");
                        }
                        else{
                            ataque = p1.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex = ataque/2;
                            int res=p2.Getvida()+p2.Getdefensa()-ataque-ex;
                            p2.Setvida(res);
                            p2.Setdebuff("");
                        }
                        else
                        {
                            int res=p2.Getvida()+p2.Getdefensa()-p1.Getataque();
                            p2.Setvida(res);
                        }
                        p1.SetpA(p1.GetpA()-p1.GetPA());
                    }
                    else if(sel1==2 && (p1.GetpA()-p1.GetPS())>=0)
                    {
                        int res = p1.Getcuracion()+p1.Getvida();
                        p1.SetpA(p1.GetpA()-p1.GetPS());
                    }
                    else if(sel1==3 && (p1.GetpA()-p1.GetPe())>=0)
                    {
                        p2.Setdebuff(p1.GetatqE());
                        p1.SetpA(p1.GetpA()-p1.GetPe());
                    }
                    else if(sel1==4 && (p1.GetpA()-1)>=0)
                    {
                        p1.Setbuff(p1.Getestado());
                        p1.SetpA(p1.GetpA()-1);
                        p1.SetBP();
                        if(p1.Getbuff()=="Defensa"){p1.Setdefensa(p1.Getdefensa()+5);}
                        if(p1.Getbuff()=="Fuerza"){p1.Setataque(p1.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p2.Getvida()<0){gana=1;break;}
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                    pelea6();
                    cout<<"jugador dos elja que hacer.....\n";
                    cout<<p2;
                    cin>>sel2;
                    if(sel2==1 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int ataque;
                        if(p2.Getdebuff()=="debil")
                        {
                            ataque = (p2.Getataque()/4)*3;
                            p2.Setdebuff("");
                        }
                        else{
                            ataque = p2.Getataque();
                        }
                        if(p2.Getdebuff() == "vulnerable")
                        {
                            int ex =  ataque/2;
                            int res=p1.Getvida()+p1.Getdefensa()-ataque-ex;
                            p1.Setvida(res);
                            p1.Setdebuff("");
                        }
                        else
                        {
                            int res=p1.Getvida()+p1.Getdefensa()-ataque;
                            p1.Setvida(res);
                        }
                        p2.SetpA(p2.GetpA()-p2.GetPA());
                    }
                    else if(sel2==2 && (p2.GetpA()-p2.GetPA())>=0)
                    {
                        int res = p2.Getcuracion()+p2.Getvida();
                        p2.SetpA(p2.GetpA()-p2.GetPS());
                    }
                    else if(sel2==3 &&  (p2.GetpA()-p2.GetPe())>=0)
                    {
                        p1.Setdebuff(p2.GetatqE());
                        p2.SetpA(p2.GetpA()-p2.GetPe());
                    }
                    else if(sel2==4 && (p2.GetpA()-1)>=0)
                    {
                        p2.Setbuff(p2.Getestado());
                        p2.SetpA(p2.GetpA()-1);
                        p2.SetBP();
                        if(p2.Getbuff()=="Defensa"){p2.Setdefensa(p2.Getdefensa()+5);}
                        if(p2.Getbuff()=="Fuerza"){p2.Setataque(p2.Getataque()+5);}
                    }
                    else{
                        cout<<"Puntos de ataque insuficientes\n";
                    }
                    if(p1.GetpA()<=0 && p2.GetpA()<=0){cout<<"Empate\n";gana=0;break;}
                    clearConsole();
                }
                if(p1.Getvida()<=0){gana=2;}
            }

        }
        
        cout<<"Gano el jugador "<<gana<<"\n";
        arch(gana);
        cout<<"volver a jugar elja 0\n";
        cout<<"presione cualquier otro numero si no \n";
        cin>>a;

    }
}