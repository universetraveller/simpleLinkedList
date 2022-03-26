#include "LinkedList.h"
template<typename elemtype>
void LinkedList<elemtype>::pop(unsigned place){
	//弹出某一位置的节点
	if (place == 0) {
		Node<elemtype>* tempPointer = root_pointer_;
		root_pointer_ = root_pointer_->NextP();
			delete tempPointer;
	}
	else {
		Node<elemtype>* tempPointer = this->getPlacePointer(place);
		this->getPlacePointer(place - 1)->setNext(tempPointer->NextP());
			delete tempPointer;
	}
}
template<typename elemtype>
void LinkedList<elemtype>::merge(LinkedList<elemtype>& rightvalue){
	last_node_->setNext(rightvalue.root_pointer_);
	last_node_ = rightvalue.last_node_;
	rightvalue.is_sub_ = true;
}
template <typename elemtype>
void LinkedList<elemtype>::push_back(elemtype input) {
	Node<elemtype>* TempPointer = new Node<elemtype>(input);
	this->last_node_->setNext(TempPointer);	//设置后继
	this->last_node_ = TempPointer;		//更新最后节点
}

template<typename elemtype>
void LinkedList<elemtype>::push_front(elemtype input){
	Node<elemtype>* tempPointer = new Node<elemtype>(input);
	tempPointer->setNext(root_pointer_);
	root_pointer_ = tempPointer;
}

template<typename elemtype>
void LinkedList<elemtype>::insert(elemtype input, unsigned place){
	Node<elemtype>* tempPointer = new Node<elemtype>(input);
	Node<elemtype>* placePointer = this->getPlacePointer(place);
	tempPointer->setNext(placePointer->NextP());
	placePointer->setNext(tempPointer);
}

template<typename elemtype>
void LinkedList<elemtype>::insert(elemtype input, Node<elemtype>* place){
	if (!place) {
		place = last_node_;
	}
	Node<elemtype>* tempPointer = new Node<elemtype>(input);
	tempPointer->setNext(place->NextP());
	place->setNext(tempPointer);
}

template <typename T>
void LinkedList<T>::Print_cout()const {
	Node<T>* PrintPointer = this->root_pointer_;
	for (; PrintPointer != last_node_;) {
		std::cout << PrintPointer->getElement();
		PrintPointer = PrintPointer->NextP();
	}
	std::cout << PrintPointer->getElement();
}

template <typename U>
unsigned LinkedList<U>::size()const {
	static unsigned size_of_list = 0;
	Node<U>* COUNTER=this->root_pointer_;  //设置为static可减少计算，但属于危险行为
	while (COUNTER!=last_node_){
		COUNTER=COUNTER->NextP();
		size_of_list++;
	}
	size_of_list++;
	return size_of_list;
}

template<typename elemtype>
Node<elemtype>* LinkedList<elemtype>::getPlacePointer(unsigned place) const{
	unsigned counter = 0;
	Node<elemtype>* returnP = root_pointer_;
	while (counter<place){
		returnP = returnP->NextP();
		counter++;
	}
	return returnP;
}

template<typename elemtype>
elemtype& LinkedList<elemtype>::operator[](unsigned place){
	return getPlacePointer(place)->getElement();
}
