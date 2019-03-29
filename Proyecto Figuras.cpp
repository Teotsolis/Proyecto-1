#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
class Figura {
    protected:
    	string nombre, tipo, nombre_dado;
    	
    public:
		Figura(string nom, string tip, string nom_dad){
    		nombre = nom;
    		tipo = tip;
    		nombre_dado = nom_dad;
		}
		
		string nombres(){
    		return nombre;
		}
		
		string tipos(){
    		return tipo;
		}
		string nom_dados(){
    		return nombre_dado;
		}
};

class DosD : public Figura {
    public:
        DosD(string n, string t, string nd) : Figura(n,t,nd){
            tipo = "2D";
        }
};
 
class TresD: public Figura {
    public:
		TresD(string n, string t, string nd) : Figura(n,t,nd){
            tipo = "3D";
        }
};
 
class Rectangulo: public DosD {
	private:
		float base;
		float altura;
    public:
        Rectangulo(string n, string t, string nd, float bas, float alt) : DosD(n,t,nd){
            nombre = "Rectangulo";
            base = bas;
            altura = alt;
        }
        float Area(){
        	return (base*altura);
		}
};
 
class Triangulo: public DosD {
	private:
		float base;
		float altura;
    public:
       Triangulo(string n, string t, string nd) : DosD(n,t,nd){
            nombre = "Triangulo";
        }
        float Area(){
        	return (base*altura/2);
		}
};

class Cubo: public TresD {
	private:
		float lado;
    public:
        Cubo(string n, string t, string nd, float lad) : TresD(n,t,nd){
            nombre = "Cubo";
            lado = lad;
        }
        float Area(){
        	cout << "Area().  Lado: " << lado << "Area: " << 6*lado*lado << "\n";
        	return (6*lado*lado);
		}
		float Volumen() {
    		return (lado*lado*lado);
		}
};
 
class Esfera: public TresD {
	private:
		float radio;
    public:
        Esfera(string n, string t, string nd, float rad) : TresD(n,t,nd){
            nombre = "Esfera";
            radio = rad;
        }
        float Area() {
    		return (4*3.1416*radio*radio);
		}
		float Volumen() {
    		return ((4.0/3)*3.1416*radio*radio*radio);
		}
};
 
int main(){
    string n, t, nd;
	int nl = 0;
    n = t = nd = "";
    
    char opc, opc1, opc2a, opc2b;
    
    float area, vol;
    
    area = vol = 0;
    
    vector <Figura> figuras;
    vector <Figura> :: iterator locFig;
    vector <Triangulo> triangulos;
    vector <Triangulo> :: iterator locTri;
    vector <Rectangulo> rectangulos;
    vector <Rectangulo> :: iterator locRec;
    vector <Cubo> cubos;
    vector <Cubo> :: iterator locCub;
    vector <Esfera> esferas;
    vector <Esfera> :: iterator locEsf;
    
    
    cout << "FIGURAS GEOMETRICAS";
    do{
    	cout << "\nElija una opción:\n\ta)Agregar figura\n\tb)Mostrar figuras\n\tc)Salir del programa\n";
        cin >> opc;
        cin.ignore();
        
		switch (opc){
            
			case 'a':
			cout << "\nElija una opción:\n\ta)2D\n\tb)3D\n";
			cin >> opc1;
        	cin.ignore();
        	
			switch (opc1){
        		case 'a':
        		cout << "\nElija una opción:\n\ta)Rectangulo\n\tb)Triangulo\n";
                cin >> opc2a;
                cin.ignore();
                
				switch(opc2a){
                	case 'a':
					
					break;
                    
					case 'b':{
						cout << "Ingresar nombre unico de figura: ";
                		getline(cin,nd,'\n');
						
						float bas2;
						float alt2;
    					cout << "Ingresar base del rectangulo: ";
    					cin >> bas2;
						//Cubo cub(n,t,nd,lad);
						
    					//figuras.push_back(cub);
						break;
					}
                    
					default:
                	cout << "\nNo se ha seleccionado una opción valida\n";
                }
                break;
                
				case 'b':
				cout << "\nElija una opción:\n\ta)Cubo\n\tb)Esfera\n";
                cin >> opc2b;
                cin.ignore();
                
					switch(opc2b){
                	case 'a':{
                		cout << "Ingresar nombre unico de figura: ";
                		getline(cin,nd,'\n');
						
						float lad;
    					cout << "Ingresar lado del cubo: ";
    					cin >> lad;
						Cubo cub(n,t,nd,lad);
						
    					figuras.push_back(cub);
						break;
					}
					case 'b':{
						cout << "Ingresar nombre unico de figura: ";
                		getline(cin,nd,'\n');
						
						float rad;
    					cout << "Ingresar radio mayor de la esfera: ";
    					cin >> rad;
    					
						Esfera esf(n,t,nd,rad);
						
    					figuras.push_back(esf);
    					esferas.push_back(esf);
						break;
					}
                    
					default:
                	cout << "\nNo se ha seleccionado una opción valida\n";
                }
					
				break;
            	
				default:
                cout << "\nNo se ha seleccionado una opción valida\n";
            }
            break;
            case 'b':
            	if (figuras.empty() == false){
					cout << "\n Lista de figuras:"; 
                	for (int i=0; i<figuras.size() ; i++){
                    	cout << "\n\tFigura " << i+1 << ":";
                    	locFig = figuras.begin() + i;
                    	n = locFig-> nombres();
                    	t = locFig-> tipos();
                    	nd = locFig-> nom_dados();
                    	cout << locFig->area() << "\n";
                    	area = locFig-> area();
                    	cout << area << "\n\n";
                    	
                    	cout << "\n\tFigura:" << n << "\n\tTipo:" << t << "\n\tNombre dado:" << nd << "\n\tArea:" << area << endl;
                	}
				} else 
					cout << "\nAun no se ha ingresado una figura\n";
            	
            break;
            case 'c':
                cout << "\nSaliendo del programa...\n";
            break;
            default:
                cout << "\nNo se ha seleccionado una opción valida\n";
        }
    } while (opc != 'c');
}


