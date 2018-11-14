#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
#include "pilaestatica.h"
#include "plantilla.h"
#include "listaenlazada.h"
#include "Funciones.h"
#include "Estructuras.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void concatenar(){

}


int main(int argc, char** argv) {
	
	fstream arctxt;
	char cadena1[300];
	arctxt.open("Estructuras.txt", ios::in);
	int n;
	if(arctxt.fail()){
		cout<<"error"<<endl;
		
	}else{
	
		while(true){
			
				arctxt.getline(cadena1, 3);
				cout<<"Caso "<<cadena1<<endl;
				arctxt.getline(cadena1,300);
			//	cout<<"cadena	"<<cadena1<<endl;
							char *ptr, cadena2[300];
			strcpy(cadena2, cadena1);
			  ptr = strtok(cadena1,",");//argumentos: frase, caracter delimitador
			  int cont=0;
			  char tipo1[30],  tipo2[30];
			  char tipo21[30], tipo22[30];
			  while(ptr != NULL)
			    {
			 //     cout << ptr << endl;
			      
			     cont++;	 
			     
			     if(cont==1){
			     	strcpy(tipo1, ptr);
				 }else if(cont==2){
				 	strcpy(tipo2, ptr);
				 }
			   //   cout<<cadena2<<" "<<cont<<endl;
			      ptr = strtok(NULL, ",");
    			}
    			
    			char tam1[cont-2][2];
    			int x=0;
    					  ptr = strtok(cadena2,",");//argumentos: frase, caracter delimitador
			 	
					  while(ptr != NULL)
					    {
							x++;
					   
					    	if(x>2){
					    		strcpy(tam1[x-3], ptr);
					    	//	cout<<"hola"<<tam1[x-2]<<endl;
							}
					  	
					      ptr = strtok(NULL, ",");
		    			}
		    			
		    			int auxiliarentero=0, auxentero, mayor=-1;
		    		for(int w=0;w<cont-2;w++){
		    			
		    			auxentero=atoi(tam1[w]);
		    		//	cout<<auxentero<<endl;
		    			if(auxentero>mayor){
		    				mayor=auxentero;
						}
					}	
		    		
		    	
				
				char cadena3[300];
				arctxt.getline(cadena1,300);	
				x=0;
				strcpy(cadena2, cadena1);
				strcpy(cadena3, cadena2);
				ptr = strtok(cadena1,",");
			 	
					  while(ptr != NULL)
					    {
							x++;
					      ptr = strtok(NULL, ",");
		    			}	
		    //		cout<<"Estructura tipo : "<<tipo1;
			//		cout<<"	Tipo: "<<tipo2<<endl;
					
					
					
							    	
					if(strcmp(tipo2, "numerico")==0){
						
						
					vector<pila_array<int > > obj1;
					vector<cola_circular<int > > objc;
					vector<lista_enlazada<int > > objl;
					
						pila_array<int > obj2;
						cola_circular<int >obj3;
						lista_enlazada<int > obj4;
		    		int mentera[cont-2][mayor];
		    		
		    			
		    			for(int m=0;m<cont-2;m++){
		    				if(m!=0)	arctxt.getline(cadena3,30);	
							x=0;
		    				ptr = strtok(cadena3,",");
			 	
					  	while(ptr != NULL)
					    {
					    	
					    	mentera[m][x]= atoi(ptr);
					    //	cout<<mentera[m][x]<<endl;
							x++;
					      ptr = strtok(NULL, ",");
		    			}	
		    		}
		    		
		    		
		    			if(strcmp(tipo1, "pila")==0){
		    			
		    			
		    				for(int w=0;w<cont-2;w++){
		    					
		    				// SE llena la pila 
		    				
		    						pila_array<int > obj(atoi(tam1[w]));
		    						
								for(int y=0;y<atoi(tam1[w]);y++){
									obj.agregar(mentera[w][y]);
								}
							//	obj.imprimir();
    							obj1.push_back(obj);	
							}
								arctxt.getline(cadena3,300);
								
								// lee la ultima linea del caso requerido
								// se necesita ver que hara y luego convertir
								
									ptr = strtok(cadena3,",");
			 	
									  	while(ptr != NULL)
									    {
								    		strcpy(tipo22,ptr);
											
								     	 ptr = strtok(NULL, ",");
				    					}
				    					strcpy(tipo21,cadena3);
				    				//	cout<<"Ejecucion	"<<tipo21<<"	A	"<<tipo22<<endl;
				    				cout<<tipo1<<"->"<<tipo21<<"->"<<tipo22<<endl;	
				    					
				    					if(strcmp(tipo21, "convertir")==0){
				    			
														
														for(int y=0;y<cont-2;y++){
															obj2=obj1[y];
															funciones<int > f1;
															f1.convirtiendo1(obj2, tipo22);

														}
										
										}else if(strcmp(tipo21, "mezclar")==0){
											vector<int> ventero;
											int q=0;
													for(int y=0;y<mayor;y++){
														
															for(int w=0;w<cont-2;w++){
																//if()
																obj2=obj1[w];
																if(y<obj2.getTam()){
																	ventero.push_back(obj2.retorno(y));
																
																	q++;	
																}
															}
															
														}
												
													funciones<int > f1;
													f1.mezclar(ventero, tipo22);
													
										}else if(strcmp(tipo21, "ordenar")==0){
											funciones<int > f1;
											for(int y=0;y<cont-2;y++){
												vector <int > s1;
													obj2=	obj1[y];
															for(int w=0;w<obj2.getTam();w++){
															s1.push_back(obj2.retorno(w));
														}
													s1=f1.insercionDirecta(s1, s1.size());
													f1.concatenando(s1, tipo22);	
											
											}
												
										}else{//revertir
										
												 	
														for(int y=0;y<cont-2;y++){
															obj2=obj1[y];
															funciones<int > f1;
															f1.revirtiendo1(obj2, tipo22);
														}
									}
								}else if(strcmp(tipo1, "cola")==0){
									
								for(int w=0;w<cont-2;w++){
		    					
					    				// SE llena la cola
					    				
					    					cola_circular<int > obj(atoi(tam1[w]));
					    						
											for(int y=0;y<atoi(tam1[w]);y++){
												obj.agregar(mentera[w][y]);
											}
										//	obj.imprimir();
			    							objc.push_back(obj);	
										}
								
											arctxt.getline(cadena3,300);

											ptr = strtok(cadena3,",");
			 	
												  	while(ptr != NULL)
												    {
											    		strcpy(tipo22,ptr);
														
											     	 ptr = strtok(NULL, ",");
							    					}
							    					strcpy(tipo21,cadena3);
							    					
							    				cout<<tipo1<<"->"<<tipo21<<"->"<<tipo22<<endl;	
							    					
				    						if(strcmp(tipo21, "convertir")==0){
												
												
												
														for(int y=0;y<cont-2;y++){
															obj3=objc[y];
																funciones<int > f1;
																f1.convirtiendo2(obj3, tipo22);
															}
													
											
										
											}else if (strcmp(tipo21, "mezclar")==0){
													vector<int> ventero;
														int q=0;
													for(int y=0;y<mayor;y++){
														
															for(int w=0;w<cont-2;w++){
																//if()
																obj3=objc[w];
																if(y<obj3.getTam()){
																	ventero.push_back(obj3.retorno(y));
																
																	q++;	
																}
															}
															
														}
												
													funciones<int > f1;
													f1.mezclar(ventero, tipo22);
											}else if(strcmp(tipo21, "ordenar")==0){
											 funciones<int> f1;
												for(int y=0;y<cont-2;y++){
													vector <int > s1;
												obj3=	objc[y];
															for(int w=0;w<obj3.getTam();w++){
															s1.push_back(obj3.retorno(w));
														}
													s1=f1.insercionDirecta(s1, s1.size());
													f1.concatenando(s1, tipo22);	
												}
														
											}else if(strcmp(tipo21, "revertir")==0){
													for(int y=0;y<cont-2;y++){
															obj3=objc[y];
															funciones<int > f1;
															f1.revirtiendo2(obj3, tipo22);
														}
											}
								
				    				
				    				
				    				
				    			}else {// lista enlazada
				    			for(int w=0;w<cont-2;w++){ // llenando lista enlazada int
				    					lista_enlazada<int > ll;
				    						for(int y=0;y<atoi(tam1[w]);y++){
												ll.agregar(mentera[w][y]);
											}
										objl.push_back(ll);	
				    				}
				    					arctxt.getline(cadena3,300);

											ptr = strtok(cadena3,",");
			 	
												  	while(ptr != NULL)
												    {
											    		strcpy(tipo22,ptr);
														
											     	 ptr = strtok(NULL, ",");
							    					}
							    					strcpy(tipo21,cadena3);
							    					
							    			cout<<tipo1<<"->"<<tipo21<<"->"<<tipo22<<endl;	
							    					
							   		if(strcmp(tipo21, "convertir")==0){
							   				for(int y=0;y<cont-2;y++){
															obj4=objl[y];
																funciones<int > f1;
																f1.convirtiendo3(obj4, tipo22);
															}
							   			
				    					}else if(strcmp(tipo21,"mezclar")==0){
				    						vector<vector<int> > ventero;
				    						vector<int> ventero1;
				    						vector<int> ventero2;
				    						for(int y=0;y<cont-2;y++){
				    								obj4=objl[y];
				    							ventero.push_back(obj4.retorno());
											}
														int q=0;
													for(int y=0;y<mayor;y++){
														
															for(int w=0;w<cont-2;w++){
															
																ventero1=ventero[w];
																if(y<ventero1.size()){
																ventero2.push_back(ventero1[y]);
																
																	q++;	
																}
															}
															
														}
												
													funciones<int > f1;
													f1.mezclar(ventero2, tipo22);
										}else if(strcmp(tipo21, "ordenar")==0){
												vector <int > s1;
												funciones<int >f1;
											for(int y=0;y<cont-2;y++){
													
															vector<int > vec;
															obj4=objl[y];
															vec=obj4.retorno();
															for(int y=0;y<vec.size();y++){
																s1.push_back(vec[y]);
															}
														
												}
												
												s1=f1.insercionDirecta(s1, s1.size());
												f1.concatenando(s1,tipo22);
										}else if(strcmp(tipo21, "revertir")==0){
												for(int y=0;y<cont-2;y++){
															obj4=objl[y];
															funciones<int > f1;
															f1.revirtiendo3(obj4, tipo22);
														}
										}
										
				    			
								}
								
		    			
		    				
		    			
		    		
		    			
						
		    	
		    		
				}else if(strcmp(tipo2, "caracter")==0){
					string mcaracter[cont-2][mayor];
					
						
					vector<cola_circular<string > >colas;
					vector<pila_array<string > >pilas;
					vector<lista_enlazada<string > >listas;
					pila_array<string > obj2;
						cola_circular<string >obj3;
						lista_enlazada<string > obj4;
						vector<string> s;
					for(int m=0;m<cont-2;m++){
					
					cout<<endl;
						if(m!=0)	arctxt.getline(cadena2,300);	
						x=0;
							ptr = strtok(cadena2,",");
					
						
						while(ptr != NULL)
					    {
					    	
					    	mcaracter[m][x]+=ptr;
					    
					   // 	cout<<mcaracter[m][x]<<" ";
							x++;
					      ptr = strtok(NULL, ",");
		    			}	
						
						
					}
				
					
						lista_enlazada<string> lista;
						
						arctxt.getline(cadena3,300);	
						ptr = strtok(cadena3,",");
			 	
									  	while(ptr != NULL)
									    {
								    		strcpy(tipo22,ptr);
											
								     	 ptr = strtok(NULL, ",");
				    					}
				    					strcpy(tipo21,cadena3);
				    				cout<<tipo1<<"->"<<tipo21<<"->"<<tipo22<<endl;	
											
					
					
						for(int y=0;y<cont-2;y++){	
						cola_circular<string > cola(atoi(tam1[y]));
						pila_array<string > pila(atoi(tam1[y]));
							for(int w=0;w<mayor;w++){
							
								if(strcmp(tipo1, "cola")==0){
								cola.agregar(mcaracter[y][w]);
							//	cout<<mcaracter[y][w]<<endl;
								}else if(strcmp(tipo1, "pila")==0){
										pila.agregar(mcaracter[y][w]);
										
								}else{
										lista.agregar(mcaracter[y][w]);
								}
							}
						if(strcmp(tipo1, "cola")==0)	colas.push_back(cola);
						if(strcmp(tipo1, "pila")==0)	pilas.push_back(pila);
						if(strcmp(tipo1, "lista")==0)	listas.push_back(lista);
						
							
						}
					funciones<string >f1;	
				
					if(strcmp(tipo21, "concatenar")==0){
						for(int y=0;y<cont-2;y++){
									if(strcmp(tipo1, "cola")==0){
										obj3=	colas[y];
										for(int w=0;w<obj3.getTam();w++){
											s.push_back(obj3.retorno(w));
										//	cout<<s[w]<<endl;
										}
											
									}else if(strcmp(tipo1, "pila")==0){
									
											obj2=	pilas[y];
											for(int w=0;w<obj2.getTam();w++){
											s.push_back(obj2.retorno(w));
										//	cout<<s[w]<<endl;
											}
									}else{
										vector<string > vec;
										obj4=listas[y];
										vec=obj4.retorno();
										for(int y=0;y<vec.size();y++){
											s.push_back(vec[y]);
										}
									}
								
						}
							f1.concatenando(s, tipo22);	
					}else if(strcmp(tipo21, "convertir")==0){
						for(int y=0;y<cont-2;y++){
						if(strcmp(tipo1, "pila")==0){
							obj2=pilas[y];
							f1.convirtiendo1(obj2, tipo22);
						}else if(strcmp(tipo1, "cola")==0){
							obj3=colas[y];
							f1.convirtiendo2(obj3, tipo22);
						}else{
							obj4= listas[y];
							f1.convirtiendo3(obj4, tipo22);
						}
				      }
					}else if(strcmp(tipo21, "revertir")==0){
						for(int y=0;y<cont-2;y++){
							if(strcmp(tipo1, "pila")==0){
									obj2=pilas[y];
							f1.revirtiendo1(obj2, tipo22);
							}else if(strcmp(tipo1, "cola")==0){
										obj3=colas[y];
							f1.revirtiendo2(obj3, tipo22);
							}else{
								obj4= listas[y];
								f1.revirtiendo3(obj4, tipo22);
							}
						}
						
					}else if(strcmp(tipo21, "mezclar")==0){	
											vector<string > vestring;
												if(strcmp(tipo1, "cola")==0){
													for(int y=0;y<mayor;y++){
														
															for(int w=0;w<cont-2;w++){
																//if()
																obj3=colas[w];
																if(y<obj3.getTam()){
																	vestring.push_back(obj3.retorno(y));
																
																
																}
															}
																
														}													
												}else if(strcmp(tipo1, "pila")==0){
													for(int y=0;y<mayor;y++){
														
															for(int w=0;w<cont-2;w++){
																//if()
																obj2=pilas[w];
																if(y<obj2.getTam()){
																	vestring.push_back(obj2.retorno(y));
																
																
																}
															}
																
														}
												}else{
													vector<vector<string> > vestring1;
				    						vector<string> vestring2;
				    					
				    						for(int y=0;y<cont-2;y++){
				    								obj4=listas[y];
				    							vestring1.push_back(obj4.retorno());
											}
													
													for(int y=0;y<mayor;y++){
														
															for(int w=0;w<cont-2;w++){
															
																vestring2=vestring1[w];
																if(y<vestring2.size()){
																vestring.push_back(vestring2[y]);
																
																	
																}
															}
															
														}
												}

													f1.mezclar(vestring, tipo22);
													
					}else{ // ordenar
						vector <string > s1;
						for(int y=0;y<cont-2;y++){
									if(strcmp(tipo1, "cola")==0){
										obj3=	colas[y];
										for(int w=0;w<obj3.getTam();w++){
											s1.push_back(obj3.retorno(w));
										
										}
											
									}else if(strcmp(tipo1, "pila")==0){
									
											obj2=	pilas[y];
											for(int w=0;w<obj2.getTam();w++){
											s1.push_back(obj2.retorno(w));
									
											}
									}else{
										vector<string > vec;
										obj4=listas[y];
										vec=obj4.retorno();
										for(int y=0;y<vec.size();y++){
											s1.push_back(vec[y]);
										}
									}
							}
							
							s1=f1.insercionDirecta(s1, s1.size());
							f1.concatenando(s1,tipo22);
						
					}
				}else if(strcmp(tipo2, "cadena")==0){
				
					vector<vector<string > > vecstrings;
					vector<string> s;
					string aux="";
					
						vector<cola_circular<string > >colas;
						vector<pila_array<string > >pilas;
						vector<lista_enlazada<string > >listas;
						pila_array<string > obj2;
						cola_circular<string >obj3;
						lista_enlazada<string > obj4;
						
					for(int m=0;m<cont-2;m++){
					vector<string> s2;
						cout<<endl;
						if(m!=0)	arctxt.getline(cadena2,300);	
						x=0;
							ptr = strtok(cadena2,",");
					
						
						while(ptr != NULL)
					    {
					    	
					    	aux+=ptr;
					    
					    	s2.push_back(aux);
					    	//cout<<s2[x]<<endl;
					    	aux="";
							x++;
					      ptr = strtok(NULL, ",");
		    			}	
						vecstrings.push_back(s2);
						
						
							
					}
					arctxt.getline(cadena3,300);	
							ptr = strtok(cadena3,",");
			 	
									  	while(ptr != NULL)
									    {
								    		strcpy(tipo22,ptr);
											
								     	 ptr = strtok(NULL, ",");
				    					}
				    					strcpy(tipo21,cadena3);
				    				cout<<tipo1<<"->"<<tipo21<<"->"<<tipo22<<endl;	
				    				
						for(int y=0;y<cont-2;y++){	
						cola_circular<string > cola(atoi(tam1[y]));
						pila_array<string > pila(atoi(tam1[y]));
						lista_enlazada<string> lista;
						s=vecstrings[y];
							for(int w=0;w<atoi(tam1[y]);w++){
							
								if(strcmp(tipo1, "cola")==0){
									
									cola.agregar(s[w]);
								//	cout<<s[w]<<endl;
								}else if(strcmp(tipo1, "pila")==0){
										pila.agregar(s[w]);
										
								}else{
										lista.agregar(s[w]);
								}
							}
						if(strcmp(tipo1, "cola")==0){
							colas.push_back(cola);	
						}else	if(strcmp(tipo1, "pila")==0){
							pilas.push_back(pila);
						}else if(strcmp(tipo1, "lista")==0){
							listas.push_back(lista);
						}	
						
							
						}
						funciones<string >f1;
					if(strcmp(tipo21, "concatenar")==0){
						vector <string > s1;
							for(int y=0;y<cont-2;y++){
									if(strcmp(tipo1, "cola")==0){
										obj3=	colas[y];
										for(int w=0;w<obj3.getTam();w++){
											s1.push_back(obj3.retorno(w));
										
										}
											
									}else if(strcmp(tipo1, "pila")==0){
									
											obj2=	pilas[y];
											for(int w=0;w<obj2.getTam();w++){
											s1.push_back(obj2.retorno(w));
									
											}
									}else{
										vector<string > vec;
										obj4=listas[y];
										vec=obj4.retorno();
										for(int y=0;y<vec.size();y++){
											s1.push_back(vec[y]);
										}
									}
							}
									f1.concatenando(s1, tipo22);	
					}else if(strcmp(tipo21, "convertir")==0){
					
							for(int y=0;y<cont-2;y++){
						if(strcmp(tipo1, "pila")==0){
							obj2=pilas[y];
							f1.convirtiendo1(obj2, tipo22);
						}else if(strcmp(tipo1, "cola")==0){
							obj3=colas[y];
							f1.convirtiendo2(obj3, tipo22);
						}else{
							obj4= listas[y];
							f1.convirtiendo3(obj4, tipo22);
							}
						}
					}else if(strcmp(tipo21, "mezclar")==0){
				
												vector<string > vestring;
												if(strcmp(tipo1, "cola")==0){
													for(int y=0;y<mayor;y++){
														
															for(int w=0;w<cont-2;w++){
															
																obj3=colas[w];
															
																if(y<obj3.getTam()){
																	vestring.push_back(obj3.retorno(y));
														//			cout<<obj3.retorno(y)<<endl;
																
																}
															}
																
														}													
												}else if(strcmp(tipo1, "pila")==0){
													for(int y=0;y<mayor;y++){
														
															for(int w=0;w<cont-2;w++){
																//if()
																obj2=pilas[w];
																if(y<obj2.getTam()){
																	vestring.push_back(obj2.retorno(y));
																	
																
																}
															}
																
														}
												}else{
																vector<vector<string> > vestring1;
							    								vector<string> vestring2;
							    					
							    								for(int y=0;y<cont-2;y++){
							    										obj4=listas[y];
							    									vestring1.push_back(obj4.retorno());
																	}
																
																for(int y=0;y<mayor;y++){
																	
																		for(int w=0;w<cont-2;w++){
																		
																			vestring2=vestring1[w];
																			if(y<vestring2.size()){
																			vestring.push_back(vestring2[y]);
																				
																				
																			}
																		}
																		
																	}
												}

													f1.mezclar(vestring, tipo22);
													
					
					}else if(strcmp(tipo21, "revertir")==0){
						for(int y=0;y<cont-2;y++){
							if(strcmp(tipo1, "pila")==0){
									obj2=pilas[y];
							f1.revirtiendo1(obj2, tipo22);
							}else if(strcmp(tipo1, "cola")==0){
										obj3=colas[y];
							f1.revirtiendo2(obj3, tipo22);
							}else{
								obj4= listas[y];
								f1.revirtiendo3(obj4, tipo22);
							}
						}
					}else if(strcmp(tipo21, "ordenar")==0){
						vector <string > s1;
						for(int y=0;y<cont-2;y++){
									if(strcmp(tipo1, "cola")==0){
										obj3=	colas[y];
										for(int w=0;w<obj3.getTam();w++){
											s1.push_back(obj3.retorno(w));
										
										}
											
									}else if(strcmp(tipo1, "pila")==0){
									
											obj2=	pilas[y];
											for(int w=0;w<obj2.getTam();w++){
											s1.push_back(obj2.retorno(w));
									
											}
									}else{
										vector<string > vec;
										obj4=listas[y];
										vec=obj4.retorno();
										for(int y=0;y<vec.size();y++){
											s1.push_back(vec[y]);
										}
									}
							}
							
							s1=f1.insercionDirecta(s1, s1.size());
							f1.concatenando(s1,tipo22);
						
					}
					
					
				}
							
			
				
			
			if(arctxt.eof()){
				break;
			}	
		}
		
		arctxt.close();	
		
	}
	
	
	
	return 0;
}
