#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {

    private:
        T* arr;
	int max;
	int n;
	static const int MINSIZE = 10;
	
	void resize(int new_size){

		if(new_size < MINSIZE){
			new_size = MINSIZE;
		}

		if (new_size < n) {
			n = new_size;
		}

		T* new_arr = new T[new_size]; 

		for(int i = 0; i < n; i++){
			new_arr[i] = arr[i];
		}
		
		delete[] arr;

		arr=new_arr;
		max=new_size;
	}

    public:
		
	void insert(int pos,T e){

	if(pos < 0 || pos > n){
		throw std::out_of_range("Posicón fuera del rango válido");
	}


	if(n == max){
		resize(max + 1);
	}


	if(pos < n){ 
		
		for(int i = n; i > pos; i--){
			arr[i] = arr[i-1];
		}
	}

	arr[pos] = e;
	n++;
	}	
	
	void append(T e){
	
		if(n == max){
			resize(max + 1);
		}
		
		arr[n] = e;
		n++;
	}


	void prepend(T e){

		if(n==max){
			resize(max + 1);
		}

		if(n > 0){
			for(int i = n; i > 0; i--){
				arr[i]=arr[i-1];
			}
		}

		arr[0] = e;
		n++;
	}

	T remove(int pos){

		if(pos < 0 || pos >= n){
			throw std::out_of_range("fuera de rango");
		}

		T aux = arr[pos];
		
		for(int i = pos; i < n - 1; i++){
			arr[i] = arr[i+1];
		}
		
		n--;

		return aux;
	}

	T get(int pos){

	       if(pos < 0 || pos >= n){
			throw std::out_of_range("fuera de rango");
	       }

	       return arr[pos];

	}

	int search(T e){

		for(int i = 0 ; i < n ; i++){
			if(arr[i] == e){
				return i;
			}
		}
		return -1;
	}

	bool empty(){

		if( n == 0 ){
			return true;
		}

		return false;
	}

	int size(){
		return n;
	}	

        ListArray(){
		
		arr = new T[MINSIZE];
		max = MINSIZE;
		n = 0;

	}

	~ListArray(){
		delete[] arr;
	}


	T operator[](int pos){
		
		if(pos < 0 || pos >= n){
			throw std::out_of_range("esta fuera de rango");
               }
			
		return arr[pos];	

	}

	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){

		out << "[";

		for (int i = 0; i < list.n; ++i) {
        		out << list.arr[i];
        		if (i < list.n - 1) {
        		    out << ", ";
        		}
    		}
    		out << "]";
    		return out;
	}



};




