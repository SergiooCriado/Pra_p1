#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>* first;
	int n;

    public:


	ListLinked(){
		
		first = nullptr;
		n=0;

	}

	~ListLinked(){
		
		Node<T>* current = first;
		while(current != nullptr){

			Node<T>* next_node = current->next;
			delete current;
			current = next_node;

		}
	}

	T operator[](int pos) {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera del rango válido [0, size()-1]");
            }

            Node<T>* current = first;

            for (int i = 0; i < pos; ++i) {
                current = current->next;
            }

            return current->data;
	



	}


	friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
	out << "[";
            Node<T>* current = list.first;
            while (current != nullptr) {
                out << current->data;
                if (current->next != nullptr) {
                    out << ", ";
                }
                current = current->next;
            }
            out << "]";
            return out;
	}
};
	
