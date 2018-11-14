template<class T>
class NodoA
{
	private: 
		// enlace a otro NodoA, interpretado como el NodoA
		NodoA<T>* link_hd; // hijo derecho del NodoA actual
		// enlace a otro Nodo, interpretado como el NodoA
		NodoA<T>* link_hi; // hijo izquierdo del NodoA actual
		T* info; // campo de informacon asociada al NodoA
		int nivel; // nivel del NodoA en su Arbol
		int altura_der; // altura del subArbol derecho del NodoA
		int altura_izq; // altura del subArbol izquierdo del NodoA
		int altura; // altura del subArbol más grande del NodoA
		int factorE; // factor de equilibrio del NodoA
		bool hoja; // determina si el NodoA es una hoja en su arbol
	public:
		/**
		 *	@brief inicializa el NodoA
		 *	@since 1.0
		 *	@param T* campo de informacion del NodoA
		 */
		explicit NodoA( T* inf ) : info( inf ) 
		{ 
			this->link_hd = this->link_hi = NULL;
			this->altura = this->altura_der = this->altura_izq = 0;
			this->nivel = this->factorE = 0;
			this->hoja = true; 
		} // fin del NodoA
		~NodoA(); // destructor
		bool isHoja() const; // retorna determinación acerca de si el NodoA es una hoja
		NodoA<T>* getLink_hd() const; // retorna enlace predecesor
		NodoA<T>* getLink_hi() const; // retorna enlance sucesor
		T* getInfo() const; // retorna apuntador a campo de información del Nodo
		int getNivel() const; // retorn nivel del NodoA en su Arbol
		int getAltura_der() const; // retorna altura del subArbol derecho del NodoA
		int getAltura_izq() const; // retorna altura del subArbol izquierdo del NodoA
		int getAltura() const; // retorna altura del subArbol más grande del NodoA
		int getFactorE() const; // retorna el factor de equilibrio del NodoA
		void setLink_hd( NodoA<T>* const ); // establece predecesor
		void setLink_hi( NodoA<T>* const ); // establece sucesor
		void setInfo( T* const ); // establece campo info 
		void setInfo( T ); // establece campo info
		void setNivel( int ); // establece el nivel del NodoA en su Arbol
		void setAltura_der( int ); // establece altura del subArbol derecho del NodoA
		void setAltura_izq( int ); // establece altura del subArbol izquierdo del NodoA
		void setAltura( int ); // establece altura del subArbol más grande del NodoA
		void setFactorE( int ); // establece factor de equilibrio del NodoA
		void actualizar(); // actualiza atributos del NodoA
}; // fin de NodoA



template<class T> NodoA<T>::~NodoA()
{
	this->link_hd = this->link_hi = NULL;
	this->info = NULL;
	this->altura = this->altura_der = this->altura_izq =
		this->factorE = this->nivel = this->hoja = 0;
} // fin del destructor



 template<class T> bool NodoA<T>::isHoja() const
 {
	return this->hoja; // retorna atributo
 } // fin de isHoja


 template<class T> NodoA<T>* NodoA<T>::getLink_hd() const
 {
	return this->link_hd; // retorna apuntador
 } // fin de getLink_hd
 
 

template<class T> NodoA<T>* NodoA<T>::getLink_hi() const
{
	return this->link_hi; // retorna referencia
} // fin de getLink_hi

template<class T> T* NodoA<T>::getInfo() const 
{
	
	return this->info; // retorna apuntador a campo info
} // fin de getInfo




template<class T> int NodoA<T>::getNivel() const
{
	return this->nivel;
} // fin de getNivel


template<class T> int NodoA<T>::getAltura_der() const
{
	return this->altura_der;
} // fin de getAltura_der



template<class T> int NodoA<T>::getAltura_izq() const
{
	return this->altura_izq;
} // fin de getAltura_izq



template<class T> int NodoA<T>::getAltura() const
{
	return this->altura;
} // fin de getAltura



template<class T> int NodoA<T>::getFactorE() const
{
	return this->factorE;
} // fin de getFactorE


template<class T> void NodoA<T>::setLink_hd( NodoA<T>* const hd ) 
{
	this->link_hd = hd;
} // fin de de setLink_hd



template<class T> void NodoA<T>::setLink_hi( NodoA<T>* const hi ) 
{
	this->link_hi = hi;
} // fin de de setLink_hi


template<class T> void NodoA<T>::setInfo( T* const inf ) 
{
	delete this->info; // libero campo info actual
	this->info = inf; // referencio al nuevo campo info
} // fin de de setLink_ext



template<class T> void NodoA<T>::setInfo( T inf ) 
{
	*this->info = inf; // nuevo campo info
} // fin de de setLink_ext



template<class T> void NodoA<T>::setNivel( int nivel )
{
	this->nivel = nivel;
} // fin de de setNivel



template<class T> void NodoA<T>::setAltura_der( int altura_der )
{
	this->altura_der = altura_der;
} // fin de de setAltura_der


 
template<class T> void NodoA<T>::setAltura_izq( int altura_izq )
{
	this->altura_izq = altura_izq;
} // fin de de setAltura_izq



template<class T> void NodoA<T>::setAltura( int altura )
{
	this->altura = altura;
} // fin de de setAltura



template<class T> void NodoA<T>::setFactorE( int factorE )
{
	this->factorE = factorE;
} // fin de de setFactorE



template<class T> void NodoA<T>::actualizar()
{
	this->altura = ( this->altura_der > this->altura_izq ? 
		this->altura_der : this->altura_izq );
	this->hoja = ( this->altura == 0 ); 
		
	this->factorE = this->altura_der - this->altura_izq;
} // fin de de actualizar
