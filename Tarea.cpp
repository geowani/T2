#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
int menu(){
	int x;
	system("cls");
	cout<<"---------Menu principal----------"<<endl<<endl;
	cout<<"1. Agregar registros"<<endl;
	cout<<"2. Ver registros"<<endl;
	cout<<"3. Buscar registros"<<endl;
	cout<<"4. Modificar registros"<<endl;
	cout<<"5. Eliminar registros"<<endl;
	cout<<"6. Salir"<<endl;
	cout<<endl;
	cout<<"Ingrese opcion a ejecutar:";
	cin>>x;
	return x;
	
}

bool verifica(string Cod){
 ifstream leer ("registro.dat", ios::in);
 string cod;
 string nom;
 string Ap;
 string dir;
 int tel;
 leer>>cod;
 while(!leer.eof()){
  leer>>Ap;
  leer>>nom;
  leer>>dir;
  leer>>tel;
  if(cod == Cod){
   cout<<"\n\n\tError: Registro duplicado.\n\n";
   system("pause");
   leer.close();
   return false;
  }
  leer>>cod;
 }
   leer.close();
   return true; 
}
void agregar(ofstream &es) {
	system("cls");
	cout<<"--------------Nuevo Registro--------------"<<endl;
	cout<<"** Ingresar la direccion sin espacios **";
	cout<<endl;
	cout<<endl;
	string cod;
	string nom;
	string ap;
	string dir;
	int tel;
	es.open("registro.dat", ios::out| ios::app);
	cout<<"Codigo:  ";
	cin>>cod;
	cout<<"Nombre:  ";
	cin>>nom;
	cout<<"Apellido:  ";
	cin>>ap;
	cout<<"Direccion:  ";
	cin>>dir;
	cout<<"Telefono:  ";
	cin>>tel;
	if(verifica(cod))
		es<<cod<<" "<<nom<<" "<<ap<<" "<<dir<<" "<<tel<<"\n";
	es.close();
	}

void verRegistros(ifstream &Lec){
	system("cls");
	string cod;
 	string nom;
 	string Ap;
 	string dir;
 	int tel;
 	Lec.open("registro.dat", ios::in);
 	if(Lec.is_open()){
	 	cout<<"--------------Registros Ingresados--------------"<<endl<<endl;
	 	Lec>>cod;
	 	while(!Lec.eof()){
			Lec>>nom;
			Lec>>Ap;
			Lec>>dir;
			Lec>>tel;
			cout<<"Codigo-----------: "<<cod<<endl;
			cout<<"Nombre-----------: "<<nom<<endl;
			cout<<"Apellido---------: "<<Ap<<endl;
			cout<<"Direccion--------: "<<dir<<endl;
			cout<<"Telefono---------: "<<tel<<endl;
			cout<<endl;
			cout<<"----------------------"<<endl;
			cout<<endl;
			Lec>>cod;
		 }
		 Lec.close();
	}else
		cout<<"Error"<<endl;
	 system("pause");
}



void buscarregistro(ifstream &Lec){
	system("cls");
	cout<<"--------------Busqueda De Registros--------------"<<endl;
	cout<<endl;
	Lec.open("registro.dat", ios::in);
	string cod, Ap, nom, dir, coux;
	int tel;
	bool encontrado = false;
	cout<<"Ingrese el codigo: ";
	cin>>coux;
	cout<<endl;
	Lec>>cod;
	while(!Lec.eof() && !encontrado){	
		Lec>>nom;
		Lec>>Ap;
		Lec>>dir;
		Lec>>tel;
		if(cod == coux){
			cout<<"Codigo--------: "<<cod<<endl;
			cout<<"Nombre--------: "<<nom<<endl;
			cout<<"Apellido------: "<<Ap<<endl;
			cout<<"Direccion-----: "<<dir<<endl;
			cout<<"Telefono------: "<<tel<<endl;
			cout<<"----------------------"<<endl;
			encontrado = true;
		}	
		Lec>>cod;
	}
	Lec.close();
	if(!encontrado){
	cout<<"DATO NO ENCONTRADO"<<endl<<endl;
    }
	system("pause");
}

void modificar(ifstream &Lec){
	system("cls");
 	string nom;
 	string Ap;
	string cod;
	string dir;
	int tel;
	string coaux;
	string nomaux;
	string Apaux;
	string dirux;
	int telux;
	Lec.open("registro.dat", ios::in);
	ofstream aux("auxiliar.dat", ios::out);
	if(Lec.is_open()){
		cout<<"--------------Modificar Registros--------------"<<endl;
		cout<<"Ingrese el codigo:  ";
		cin>>coaux;
		Lec>>cod;
		while(!Lec.eof()){
		  	Lec>>nom;
			Lec>>Ap;
			Lec>>dir;
			Lec>>tel;
			cout<<endl;
			if(cod == coaux){
				cout<<"Ingresar el nuevo nombre: ";
				cin>>nomaux;
				cout<<"Ingresar el nuevo apellido: ";
				cin>>Apaux;
				cout<<"Ingresar la nueva direccion: ";
				cin>>dirux;
				cout<<"Ingresar el nuevo telefono: ";
				cin>>telux;
				aux<<cod<<" "<<nomaux<<" "<<Apaux<<" "<<dirux<<" "<<telux<<"\n";
				cout<<"--------------------------------------"<<endl;
			}else{
				aux<<cod<<" "<<nom<<" "<<Ap<<" "<<dir<<" "<<tel<<"\n";
			}
			
			Lec>>cod;
			Lec>>nom;
		}
		Lec.close();
		aux.close();
		
	}else 
		cout<<"Error"<<endl;
	remove ("registro.dat");
	rename("auxiliar.dat", "registro.dat");
}

void eliminar(ifstream &Lec){
	system("cls");
	string nom;
 	string Ap;
 	string cod;
	string dir;
	int tel;
	int bo;
	string coaux;
	string Apaux;
	string nomaux;
	string diraux;
	int telux;
	Lec.open("registro.dat", ios::in);
	ofstream aux("auxiliar.dat", ios::out);
	if(Lec.is_open()){
		cout<<"--------------ID a modificar--------------------"<<endl;
		cout<<"Ingrese el codigo:  ";
		cin>>coaux;
		Lec>>cod;
		while(!Lec.eof()){
		  	Lec>>nom;
			Lec>>Ap;
			Lec>>dir;
			Lec>>tel;
			if(cod == coaux){
				cout<<endl;
				cout<<"------Fue eliminada existosamente-----"<<endl;
				Sleep(1500);
			}else{
				aux<<cod<<" "<<nom<<" "<<Ap<<" "<<dir<<" "<<tel<<"\n";
				
			}
			
			Lec>>cod;
			Lec>>nom;
		}
		Lec.close();
		aux.close();
	}else 
		cout<<"Error"<<endl;
	remove ("registro.dat");
	rename("auxiliar.dat", "registro.dat");	
	
}

int main(){
	ofstream Esc;
	ifstream Lec;
	int op;
	do{
		
		system("cls");
		op = menu();
		switch(op){
			case 1:
				agregar(Esc);
			break;
			case 2:
				verRegistros(Lec);
			break;
			case 3:
				buscarregistro(Lec);
			break;
			case 4:
				modificar(Lec);
			break;
			case 5:
				eliminar(Lec);
			break;
		}	
	}while(op != 6);
		system("cls");
		    EXIT_SUCCESS; 
		    cout<<endl;
		    cout<<"Hasta luego!"<<endl;
			system ("pause");
	return 0;
}
