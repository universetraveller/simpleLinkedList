#pragma once
#include "Node.h"
#include <iostream>
template <typename elemtype>
class LinkedList {
public:
	void Print_cout()const;		//��ӡȫ��Ԫ��
	LinkedList(){
		root_pointer_ = new Node<elemtype>;		//���ýڵ��ʼ��
		last_node_ = root_pointer_;
	}
	LinkedList(elemtype input) {
		root_pointer_ = new Node<elemtype>(input);		//���ýڵ��ʼ��
		last_node_ = root_pointer_;
	}
	~LinkedList() {
		if (!is_sub_) {
			this->erase();  //�Է���list����
		}
	}
	void pop(unsigned place=0);
	void erase() {
		for (; root_pointer_ != last_node_;) {
			this->pop();
		}
		this->pop();
	}
	bool empty() {
		return this->root_pointer_ == 0;
	}
	void merge(LinkedList<elemtype>&);
	void push_back(elemtype);
	void push_front(elemtype);
	void insert(elemtype, unsigned place=0);  //ĳλ��֮�����
	void insert(elemtype, Node<elemtype>*);  //λ����ָ���ʾ����ʽ
	unsigned size()const;
	Node<elemtype>* getPlacePointer(unsigned)const;
	elemtype& operator[](unsigned);
private:
	Node<elemtype>* root_pointer_ = 0;	//���ڵ�
	Node<elemtype>* last_node_ = 0;	//���Ľڵ㣨�޺�̣�
	bool is_sub_;  //��Ǹ�listΪ��list��֮ǰû�������������������list����bug
};